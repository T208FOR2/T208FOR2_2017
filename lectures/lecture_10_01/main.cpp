#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string replace_with_substr(string s, string x, string y);

int main() {
    string texti,x,y;
    getline(cin, texti);
    cin >> x >> y;

    cout << replace_with_substr(texti,x,y) << endl;

    return 0;
}


string replace_with_substr(string s, string x, string y) {
    unsigned int pos;

    pos = s.find(x);
    while (pos < s.length()) {
        s = s.substr(0, pos) + y + s.substr(pos+x.length(), s.length());
        pos = s.find(x, pos+1);
    }

    return s;
}


