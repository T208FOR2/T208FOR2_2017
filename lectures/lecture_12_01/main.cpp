#include <iostream>

using namespace std;

const int NUM = 100;

int main()
{
    int n;
    int fylki[NUM];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> fylki[i];
    }

    cout << fylki << endl;

    return 0;
}
