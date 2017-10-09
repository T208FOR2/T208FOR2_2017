#include <iostream>
#include <string>

using namespace std;

int main()
{
    int shift;
    string texti;

    cin >> shift >> texti;

    texti = texti.substr(0, texti.length()-1);

    cout << texti << endl;

    return 0;
}
