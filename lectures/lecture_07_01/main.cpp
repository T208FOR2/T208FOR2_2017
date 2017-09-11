#include <iostream>

using namespace std;

void get_input(int& a, int& b);

bool numbers_are_ok(int a, int b);
int round_number(int a, int b);

int main()
{
    int a,b;
    get_input(a,b);

    if (numbers_are_ok(a,b)) {
        cout << round_number(a,b) << endl;
    }
    else {
        cout << "Error" << endl;
    }

    return 0;
}

int round_number(int a, int b) {
    int result = ((a) / b) * b;
    int remainder = a - result;
    if (remainder >= b/2) {
        return result + b;
    }
    else {
        return result;
    }
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
