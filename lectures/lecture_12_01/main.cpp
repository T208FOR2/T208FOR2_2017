#include <iostream>
#include <string>

using namespace std;

string shift_by_one(string texti);

int main()
{
    int shift;
    string texti;

    cin >> shift >> texti;

    texti = shift_by_one(texti);

    cout << texti << endl;

    return 0;
}

string shift_by_one(string texti) {
    return texti[texti.length()-1] + texti.substr(0, texti.length()-1);
}
