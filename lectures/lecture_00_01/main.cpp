#include <iostream>
#include <string>
using namespace std;

int main()
{
    string nafn;
    int aldur;

    cout << "What's your name? ";
    cin >> nafn;

    cout << "How old are you? ";
    cin >> aldur;

    cout << "Hi " << nafn << endl;
    cout << "Welcome to T208FOR2" << endl;

    if (aldur >= 20) {
        cout << "Congratulations, you can buy beer!" << endl;
    }
    return 0;
}
