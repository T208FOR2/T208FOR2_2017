#include <iostream>

using namespace std;

int main()
{
    int n, current, themax;
    int sum = 0;
    bool firstiteration = true;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> current;
        sum += current;

        if (firstiteration || current > themax) {
            themax = current;
        }
        firstiteration = false;
    }

    cout << "The average is " << static_cast<double>(sum)/n << endl;
    cout << "The largest number is " << themax << endl;

    return 0;
}
