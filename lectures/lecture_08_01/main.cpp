#include <iostream>

using namespace std;

const int N = 10;

int main()
{
    int tolur[N];

    for (int i = 0; i < N; i++) {
        cin >> tolur[i];
    }
    cout << "----------------" << endl;

    for (int i = N-1; i >= 0; i--) {
        cout << tolur[i] << endl;
    }

    return 0;
}
