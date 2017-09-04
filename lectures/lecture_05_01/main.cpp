#include <iostream>

using namespace std;

int testfall(int& tala);

int main()
{
    int a;
    cin >> a;

    cout << a << endl;
    cout << testfall(a) << endl;
    cout << a << endl;

    return 0;
}


int testfall(int& tala) {
    tala = tala + 1;
    return tala;
}


