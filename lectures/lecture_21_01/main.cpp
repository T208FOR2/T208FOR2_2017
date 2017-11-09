#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a,b,texti;

    cin >> a >> b;
    getline(cin, texti);

    // go through texti and replace a with b
    // strip whitespace and print out.

    cout << "\"" << a << "\"" << endl;
    cout << "\"" << b << "\"" << endl;
    cout << "\"" << texti << "\"" << endl;

    return 0;
}
