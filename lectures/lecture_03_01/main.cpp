#include <iostream>

using namespace std;

int main()
{
    int staersta, naeststaersta, current;
    bool fyrstaitrun = true;

    for (int i = 0; i < 10; i++) {
        cin >> current;

        if (fyrstaitrun || current > staersta) {
            naeststaersta = staersta;
            staersta = current;

            fyrstaitrun = false;
        }
        else if (current > naeststaersta) {
            naeststaersta = current;
        }
    }

    cout << "The largest number is " << staersta << endl;
    cout << "The second largest is " << naeststaersta << endl;

    return 0;
}
