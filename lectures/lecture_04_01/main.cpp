#include <iostream>

using namespace std;

const int HEIGHT = 10;
const int WIDTH = 20;

enum directions{UP,RIGHT,DOWN,LEFT};

int main()
{
    int x = WIDTH / 2, y = HEIGHT / 2, d = UP;
    int treasure_x = WIDTH / 3, treasure_y = HEIGHT / 3;
    int monster_x = 0, monster_y = 0;

    char input = '.';

    bool treasure_found = false;
    bool caught_by_monster = false;

    while ( input != 'q' ) {
        if (input == 'r') {
            d = (d + 1) % 4;
        }
        else if (input == 'l') {
            d = d - 1;
            if (d < 0) {
                d = 3;
            }
        }
        else if (input == 's') {
            if (d == RIGHT) {
                x = x + 1;
                if (x >= WIDTH) {
                    x = 0;
                }
            }
            else if (d == LEFT) {
                x = x - 1;
                if (x < 0) {
                    x = WIDTH - 1;
                }
            }
            else if (d == UP) {
                y = y - 1;
                if (y < 0) {
                    y = HEIGHT-1;
                }
            }
            else if (d == DOWN) {
                y = y + 1;
                if (y >= HEIGHT) {
                    y = 0;
                }
            }
        }

        for (int row = 0; row < HEIGHT; row++) {
            for (int column = 0; column < WIDTH; column++) {
                if (column == x && row == y) {
                    if (monster_x == x && monster_y == y) {
                        cout << "X";
                        caught_by_monster = true;
                    }
                    else if (treasure_x == x && treasure_y == y) {
                        cout << "!";
                        treasure_found = true;
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
                else {
                    cout << ".";
                }
            }
            cout << endl;
        }

        if (treasure_found) {
            cout << "You've found the treasure!!!" << endl;
            input = 'q';
        }
        else {
            cout << "Next action? (q=quit,r=turn right,l=turn left,s=take a step) ";
            cin >> input;
        }
    }

    return 0;
}
