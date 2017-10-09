#include <iostream>
#include <string>

using namespace std;

int main()
{
    int shift;
    string texti;

    cin >> shift >> texti;

    texti = texti.substr(1, texti.length());

    cout << texti << endl;

    return 0;
}
