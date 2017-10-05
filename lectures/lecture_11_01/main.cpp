#include <iostream>

using namespace std;

string getnexthashtag(string inputline, unsigned int& pos);

int main()
{
    unsigned int pos = 0;
    string inputline = "Something #One, #Two #Three#Four...#Five and something";

    cout << getnexthashtag(inputline, pos);

    return 0;
}

string getnexthashtag(string inputline, unsigned int& pos) {
    unsigned int hashstart, hashend;
    hashstart = inputline.find("#", pos);
    hashend = inputline.find_first_not_of("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", hashstart+1);
    return inputline.substr(hashstart, hashend - hashstart);
}
