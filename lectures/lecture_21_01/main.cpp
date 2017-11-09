#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string replace_text(string texti, string a, string b);
string strip_text(string texti);

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

    texti = strip_text(texti);

    cout << "\"" << texti << "\"" << endl;

    return 0;
}

string replace_text(string texti, string a, string b) {
    unsigned int pos = texti.find(a);
    while (pos < texti.length()) {
        texti = texti.substr(0, pos) + b + texti.substr(pos + a.length(), texti.length());
    }


}


string strip_text(string texti) {
    while ( isspace(texti[0]) ) {
        texti = texti.substr(1, texti.length());
    }
    while ( isspace(texti[texti.length()-1]) ) {
        texti = texti.substr(0, texti.length() -1);
    }
    return texti;
}






