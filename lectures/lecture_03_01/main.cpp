#include <iostream>

using namespace std;


int main()
{
    int a,b;

    cout << "Integer division practice, write two numbers: ";
    cin >> a >> b;

    if ( a / b > 0 ) {
        cout << a << " / " << b << " = " << a/b << endl;
    }

    return 0;
}
