#include <iostream>

using namespace std;

int sum(int a, int b);


int main() {
    int a,b,c;
    cin >> a >> b >> c;

    cout << a << " + " << b << " = " << sum(a,b) << endl;

    return 0;
}

int sum(int a, int b) {
    return a + b;
}
