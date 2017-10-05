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

    h = getnexthashtag(inputline, pos);
    while (h != NOHASHTAGFOUND) {



        h = getnexthashtag(inputline, pos);
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
