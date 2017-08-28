#include <iostream>

using namespace std;

int main()
{
    int staersta, current;

    for (int i = 0; i < 10; i++) {
        cin >> current;

        if ( i == 0 || current > staersta ) {
            staersta = current;
        }

    }

    cout << "The largest number is " << staersta << endl;

    return 0;
}
