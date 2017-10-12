#include <iostream>

using namespace std;

int main() {
    int n;
    int *p, *q;

    cin >> n;

    p = new int[n];
    q = p;

    for (int i = 0; i < n; i++) {
        p[i] = i*i;
    }

    for (int i = 0; i < n; i++) {
        cout << *q << " ";
        q = q + 1;
    }
    cout << endl;

    delete [] p;
    return 0;
}

