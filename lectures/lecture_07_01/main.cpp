#include <iostream>

using namespace std;

void get_input(int& a, int& b);

bool numbers_are_ok(int a, int b);

int main()
{
    int a,b;
    get_input(a,b);

    if (numbers_are_ok(a,b)) {
        cout << "Wheee!" << endl;
    }
    else {
        cout << "Fuck!!!" << endl;
    }


    return 0;
}

bool numbers_are_ok(int a, int b) {
    if (b > a) {
        return false;
    }

    while (b > 1) {
        if (b % 10 != 0) {
            return false;
        }
        b = b / 10;
    }

    return true;
}

void get_input(int& a, int& b) {
    cin >> a >> b;
}
