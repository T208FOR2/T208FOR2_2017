#include <iostream>

using namespace std;

int turn_right_cbv(int current_direction);
void turn_right_cbr(int& current_direction);


int main()
{
    int d = 0;
    char input = ' ';
    while (input != 'q') {
        if (input == 'r') {
            //d = turn_right_cbv(d);
            turn_right_cbr(d);
        }
        cout << "The direction is: " << d << endl;

        cout << "Next action? ";
        cin >> input;
    }

    return 0;
}

// call-by-value version
int turn_right_cbv(int current_direction) {
    int new_direction = (current_direction + 1) % 4;
    return new_direction;
}

// call-by-reference version
void turn_right_cbr(int& current_direction) {
    current_direction = (current_direction + 1) % 4;
}
