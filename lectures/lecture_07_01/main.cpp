#include <iostream>
#include <cmath>
using namespace std;

void get_input(int& a, int& b);

bool numbers_are_ok(int a, int b);
int round_number(int a, int b);
int round_number_v2(int a, int b);
int round_number_v3(int a, int b);

int main()
{
    int a,b;
    get_input(a,b);

    if (numbers_are_ok(a,b)) {
        cout << round_number(a,b) << endl;
        cout << round_number_v2(a,b) << endl;
        cout << round_number_v3(a,b) << endl;
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

int round_number_v2(int a, int b) {
    return ((a+b/2) / b) * b;
}

int round_number_v3(int a, int b) {
    double d = static_cast<double>(a)/b;
    int result = round(d) * b;
    return result;
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
