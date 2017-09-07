#include <iostream>

using namespace std;




int main()
{
    int d = 0;
    char input = ' ';
    while (input != 'q') {
        if (input == 'r') {
            d = (d + 1) % 4;
        }
        cout << "The direction is: " << d << endl;

        cout << "Next action? ";
        cin >> input;
    }


    return 0;
}
