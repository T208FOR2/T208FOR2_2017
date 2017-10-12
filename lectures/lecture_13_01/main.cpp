#include <iostream>

using namespace std;

int main() {
    int n;
    int *p;

    cin >> n;

    p = new int[n];

    for (int i = 0; i < n; i++) {
        p[i] = i*i;
    }

    for (int i = 0; i < n; i++) {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        p--;
    }

    delete [] p;
    return 0;
}

