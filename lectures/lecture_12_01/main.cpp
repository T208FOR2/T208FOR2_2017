#include <iostream>
#include <string>

using namespace std;

unsigned int minvalue(unsigned int x, unsigned int y);

int main()
{
    string a,b;
    unsigned int shorter_length;
    string result = "";

    cin >> a >> b;

    shorter_length = minvalue(a.length(), b.length());

    for (unsigned int i = 0; i < shorter_length; i++) {
        result = result + a[i] + b[i];
    }

    for (unsigned int i = shorter_length; i < a.length(); i++) {
        result = result + a[i];
    }
    for (unsigned int i = shorter_length; i < b.length(); i++) {
        result = result + b[i];
    }

    cout << result << endl;

    return 0;
}

unsigned int minvalue(unsigned int x, unsigned int y) {
    if (x < y) {
        return x;
    }
    return y;
}

