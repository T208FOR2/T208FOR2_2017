#include <iostream>

using namespace std;

const int NUM = 100;

int main()
{
    int n, sum = 0;
    int fylki[NUM];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> fylki[i];
        sum += fylki[i];
    }

    cout << "The average " << static_cast<double>(sum)/n << endl;

    return 0;
}
