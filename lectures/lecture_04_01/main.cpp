#include <iostream>

using namespace std;

const int HEIGHT = 10;
const int WIDTH = 20;

int main()
{
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {
            cout << ".";
        }
        cout << endl;
    }

    return 0;
}
