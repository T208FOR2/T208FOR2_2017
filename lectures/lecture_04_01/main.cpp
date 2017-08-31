#include <iostream>

using namespace std;

const int HEIGHT = 10;
const int WIDTH = 20;

enum directions{UP,RIGHT,DOWN,LEFT};

int main()
{
    int x = WIDTH / 2, y = HEIGHT / 2, d = UP;

    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
            if (column == x && row == y) {
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
            else {
                cout << ".";
            }
        }
        cout << endl;
    }

    return 0;
}
