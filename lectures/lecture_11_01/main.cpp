#include <iostream>

using namespace std;

const string NOHASHTAGFOUND = "No hashtag found";
const int NUM = 1000;

string getnexthashtag(string inputline, unsigned int& pos);

int main()
{
    unsigned int pos = 0;
    string inputline = "Something #One, #Two, #two, #TWO #Three#Four...#Five and something";
//    string inputline = "This is a line withouth hashtags.";
    string h;
    string hashtags[NUM];
    int used_n = 0;

    h = getnexthashtag(inputline, pos);
    while (h != NOHASHTAGFOUND) {
        hashtags[used_n] = h;
        used_n = used_n + 1;

        h = getnexthashtag(inputline, pos);
    }

    for (int i = 0; i < used_n; i++) {
        cout << hashtags[i] << endl;
    }

    return 0;
}

string getnexthashtag(string inputline, unsigned int& pos) {
    unsigned int hashstart, hashend;
    hashstart = inputline.find("#", pos);
    if (hashstart < inputline.length()) {
        pos = hashstart+1;
        hashend = inputline.find_first_not_of("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", hashstart+1);
        return inputline.substr(hashstart, hashend - hashstart);
    }
    else {
        return NOHASHTAGFOUND;
    }
}
