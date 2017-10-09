#include <iostream>
#include <string>

using namespace std;

int main()
{
    int shift;
    string texti;

    cin >> shift >> texti;

    texti = texti[texti.length()-1] + texti.substr(0, texti.length()-1);
    texti = texti[texti.length()-1] + texti.substr(0, texti.length()-1);

    cout << texti << endl;

    return 0;
}
