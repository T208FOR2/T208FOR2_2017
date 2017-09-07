#include <iostream>

using namespace std;

void sum(string s);
int sum(int a, int b);
int sum(int a, int b, int c);

int main() {
    int a,b,c;
    cin >> a >> b >> c;

    cout << a << " + " << b << " = " << sum(a,b) << endl;
    cout << a << " + " << b << " + " << c << " = " << sum(a,b,c) << endl;

    return 0;
}

int sum(int a, int b) {
    return a + b;
}

int sum(int a, int b, int c) {
    return a + b + c;
}
