#include <iostream>
#include <string>

using namespace std;

string shift_by_one(string texti);
string shift_by_minus_one(string texti);

int main()
{
    int shift;
    string texti;

    cin >> shift >> texti;

    if (shift > 0) {
        for (int i = 0; i < shift; i++) {
            texti = shift_by_one(texti);
        }
    }
    else {
        for (int i = shift; i < 0; i++) {
            texti = shift_by_minus_one(texti);
        }
    }

    cout << texti << endl;

    return 0;
}

string shift_by_one(string texti) {
    return texti[texti.length()-1] + texti.substr(0, texti.length()-1);
}

string shift_by_minus_one(string texti) {
    return texti.substr(1, texti.length()) + texti[0];
}
