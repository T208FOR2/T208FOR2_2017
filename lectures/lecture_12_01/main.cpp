#include <iostream>

using namespace std;

int main()
{
    int n, current;
    int sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> current;
        sum += current;
    }

    cout << "The average is " << static_cast<double>(sum)/n << endl;

    return 0;
}
