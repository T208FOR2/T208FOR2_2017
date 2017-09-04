#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;

    cout << a << " / " << b << " = " << a / b << endl;
    cout << a << " / " << b << " = " << static_cast<double>(a) / b << endl;
    cout << a << " / " << b << " = " << a / static_cast<double>(b) << endl;
    cout << a << " / " << b << " = " << static_cast<double>(a) / static_cast<double>(b) << endl;
    cout << a << " / " << b << " = " << static_cast<double>(a / b) << endl;

    return 0;
}
