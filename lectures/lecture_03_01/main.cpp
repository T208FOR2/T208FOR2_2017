#include <iostream>

using namespace std;

int main()
{
    int staersta, naeststaersta, current;
    bool fyrstaitrun = true;
    bool naeststaersta_oskilgreind = true;

    for (int i = 0; i < 10; i++) {
        cin >> current;

        if (fyrstaitrun || current > staersta) {
            if (!fyrstaitrun) {
                naeststaersta = staersta;
            }
            staersta = current;

            fyrstaitrun = false;
        }
        else if (naeststaersta_oskilgreind || current > naeststaersta) {
            naeststaersta = current;
            naeststaersta_oskilgreind = false;
        }
    }

    cout << "The largest number is " << staersta << endl;
    cout << "The second largest is " << naeststaersta << endl;

    return 0;
}
