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

    cout << tolur[0] << endl;

    cout << tolur[1] << endl;

    cout << tolur[8] << endl;

    cout << tolur[586] << endl;

    return 0;
}
