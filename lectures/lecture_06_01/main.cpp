#include <iostream>
#include <string>

using namespace std;

string sum(string s);
int sum(int a, int b);
int sum(int a, int b, int c);

int main() {
    int a,b,c;
    cin >> a >> b >> c;

    cout << a << " + " << b << " = " << sum(a,b) << endl;
    cout << a << " + " << b << " + " << c << " = " << sum(a,b,c) << endl;
    cout << sum("something") << endl;

    return 0;
}

string sum(string s) {
    cout << "i dont know how to sum \"" << s << "\"" << endl;
    return "???";
}

int sum(int a, int b) {
    return a + b;
}

int sum(int a, int b, int c) {
    return a + b + c;
}
