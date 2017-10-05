#include <iostream>

using namespace std;

int main()
{
    unsigned int hashstart, hashend;
    string inputline = "Something #One, #Two #Three#Four...#Five and something";

    hashstart = inputline.find("#", 14);
    hashend = inputline.find_first_not_of("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", hashstart+1);

    cout << inputline << endl;
    cout << "\"" << inputline.substr(hashstart+1, hashend - hashstart-1) << "\"" << endl;

    return 0;
}
