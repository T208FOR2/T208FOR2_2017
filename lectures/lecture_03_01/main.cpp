#include <iostream>

using namespace std;

int main()
{
    int staersta, naeststaersta, current;

    for (int i = 0; i < 10; i++) {
        cin >> current;

        if (current > staersta) {
            naeststaersta = staersta;
            staersta = current;
        }
        else if (current > naeststaersta) {
            naeststaersta = current;
        }
    }

    cout << "The largest number is " << staersta << endl;
    cout << "The second largest is " << naeststaersta << endl;

    return 0;
}
