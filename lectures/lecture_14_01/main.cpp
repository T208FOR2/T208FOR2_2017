#include <iostream>

using namespace std;

int main() {
    int n;
    int *p;
    cin >> n;
    p = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    delete [] p;

    return 0;
}
