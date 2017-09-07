#include <iostream>
using namespace std;

const bool EASY_MODE = false;

const int WIDTH = 20;
const int HEIGHT = 10;

const int TREASURE_X = WIDTH/3;
const int TREASURE_Y = HEIGHT/3;

enum directions{UP,RIGHT,DOWN,LEFT};

bool player_makes_a_move(int& x, int& y, int& d, char input);
char print_status_and_get_next_action(bool caught_by_monster, bool treasure_found);

bool same_place(int x1, int y1, int x2, int y2);

void turn_right(int& direction);
void turn_left(int& direction);
void take_a_step(int& x, int& y, int direction);

void monster_takes_a_step(int& monster_x, int& monster_y, int x, int y);

void print_board(int x, int y, int d, int monster_x, int monster_y, int treasure_x, int treasure_y,
                 bool caught_by_monster, bool treasure_found);

int main() {
    int d = UP, x = WIDTH/2, y = HEIGHT/2;
    int monster_x = 0, monster_y = 0;
    char input = ' ';
    bool treasure_found = false;
    bool caught_by_monster = false;

    while (input != 'q') {
        if (player_makes_a_move(x,y,d,input) || !EASY_MODE) {
            monster_takes_a_step(monster_x, monster_y, x, y);
        }

        caught_by_monster = same_place(x,y, monster_x, monster_y);
        treasure_found = same_place(x,y, TREASURE_X, TREASURE_Y);

        print_board(x,y,d,monster_x, monster_y, TREASURE_X, TREASURE_Y, caught_by_monster, treasure_found);

        input = print_status_and_get_next_action(caught_by_monster, treasure_found);
    }

    return 0;
}

bool player_makes_a_move(int& x, int& y, int& d, char input) {
    if (input == 'r') {
        turn_right(d);
        return false;
    }
    else if (input == 'l') {
        turn_left(d);
        return false;
    }
    else if (input == 's') {
        take_a_step(x,y,d);
        return true;
    }
    else {
        return false;
    }
}

char print_status_and_get_next_action(bool caught_by_monster, bool treasure_found) {
    if (caught_by_monster) {
        cout << "You'be been eaten by the monster!!!" << endl;
        return 'q';
    }
    else if (treasure_found) {
        cout << "You've found the treasure!!!" << endl;
        return 'q';
    }
    else {
        cout << "Next action? (q=quit,r=turn right, l=turn left, s=take a step) ";
        char input;
        cin >> input;
        return input;
    }

}

bool same_place(int x1, int y1, int x2, int y2) {
    return (x1 == x2 && y1 == y2);
}


void turn_right(int& direction) {
    direction = (direction + 1) % 4;
}

void turn_left(int& direction) {
    direction = direction - 1;
    if (direction < 0) {
        direction = 3;
    }
}

void take_a_step(int& x, int& y, int direction) {
    if (direction == UP) {
        y = y - 1;
        if (y < 0) {
            y = HEIGHT-1;
        }
    }
    else if (direction == RIGHT) {
        x = x + 1;
        if (x >= WIDTH) {
            x = 0;
        }
    }
    else if (direction == DOWN) {
        y = y + 1;
        if (y >= HEIGHT) {
            y = 0;
        }
    }
    else if (direction == LEFT) {
        x = x - 1;
        if (x < 0) {
            x = WIDTH-1;
        }
    }
    else {
        cout << "ERROR! Unknown direction" << endl;
    }
}

void monster_takes_a_step(int& monster_x, int& monster_y, int x, int y) {
    int best_move_x = monster_x, best_move_y = monster_y;
    int shortest_distance = HEIGHT*HEIGHT+WIDTH*WIDTH;

    for (int temp_x = monster_x - 1; temp_x <= monster_x + 1; temp_x++) {
        for (int temp_y = monster_y - 1; temp_y <= monster_y + 1; temp_y++) {
            if ((temp_x - x)*(temp_x - x) + (temp_y - y)*(temp_y - y) < shortest_distance) {
                shortest_distance = (temp_x - x)*(temp_x - x) + (temp_y - y)*(temp_y - y);
                best_move_x = temp_x;
                best_move_y = temp_y;
            }
        }
    }
    monster_x = best_move_x;
    monster_y = best_move_y;
}













void print_board(int x, int y, int d, int monster_x, int monster_y, int treasure_x, int treasure_y,
                 bool caught_by_monster, bool treasure_found)
{
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++ ) {
            if (column == x && row == y) {
                if (caught_by_monster) {
                    cout << "X";
                }
                else if (treasure_found) {
                    cout << "!";
                }
                else {
                    if (d == UP) {
                        cout << "^";
                    }
                    else if (d == RIGHT) {
                        cout << ">";
                    }
                    else if (d == DOWN) {
                        cout << "v";
                    }
                    else if (d == LEFT) {
                        cout << "<";
                    }
                    else {
                        cout << "?";
                    }
                }
            }
            else if (!caught_by_monster && column == monster_x && row == monster_y) {
                cout << "M";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }
}
