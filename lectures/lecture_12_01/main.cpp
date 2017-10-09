#include <iostream>
#include <string>

using namespace std;

unsigned int minvalue(unsigned int x, unsigned int y);

int main()
{
    string a,b;
    unsigned int shorter_length;

    cin >> a >> b;

    shorter_length = minvalue(a.length(), b.length());




    return 0;
}

int minvalue(int x, int y) {
    if (x < y) {
        return x;
    }
    return y;
}

