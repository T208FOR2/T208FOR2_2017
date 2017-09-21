#include <iostream>

using namespace std;

const int N = 10;

int round_number(double x);

int main()
{
    double numbers[N];
    for (int i = 0; i < N; i++) {
        numbers[i] = 0.0;
    }

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    cout << "---------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << round_number( numbers[i] ) << endl;
    }

    return 0;
}

int round_number(double x) {
    int round_result = (x+0.5);
    return round_result;
}
