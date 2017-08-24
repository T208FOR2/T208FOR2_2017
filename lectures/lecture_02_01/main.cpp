#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;

    if (a == b) {
        cout << "The numbers are the same!" << endl;
        cout << a << " - " << b << endl;
    }
    else if (a <= 0) {
        cout << "a is very small" << endl;
    }
    else if (b >= 1000) {
        cout << "b is pretty big" << endl;
    }
    else {
        cout << "Not the same numbers." << endl;
        cout << a << " - " << b << endl;
    }

    return 0;
}
