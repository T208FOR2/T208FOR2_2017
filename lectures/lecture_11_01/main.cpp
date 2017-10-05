#include <iostream>

using namespace std;

int main()
{
    unsigned int hashstart, hashend;
    string inputline = "Something #One, #Two #Three#Four...#Five and something";

    hashstart = inputline.find("#");
    hashend = inputline.find_first_not_of("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", hashstart+1);
    cout << inputline << endl;
    cout << pos << endl;

    return 0;
}
