#include <iostream>

using namespace std;

int main() {
    int n, m = 0;
    int *p, *q;
    cin >> n;
    p = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        m += p[i];
    }

    q = new int[m];




    for (int i = 0; i < m; i++) {
        cout << q[i] << " ";
    }
    cout << endl;

    delete [] q;
    delete [] p;

    return 0;
}
