#include <iostream>

using namespace std;

int main()
{
    int tolur[10];

    for (int i = 0; i < 10; i++) {
        cin >> tolur[i];
    }
    cout << "----------------" << endl;

    for (int i = 9; i >= 0; i--) {
        cout << tolur[i] << endl;
    }

    return 0;
}
