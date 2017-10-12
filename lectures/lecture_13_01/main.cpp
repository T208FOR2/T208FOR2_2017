#include <iostream>

using namespace std;

int main() {
    int thesize = 2, n = 0;
    int *p = new int[thesize];

    int tala;
    cin >> tala;
    while (tala >= 0) {
        p[n] = tala;
        n++;

        if (n == thesize) {
            cout << "RESIZE!!!" << endl;
            int *q = new int[thesize*2];
            for (int i = 0; i < n; i++) {
                q[i] = p[i];
            }
            delete [] p;
            p = q;
            thesize = thesize*2;
        }

        cin >> tala;
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    delete [] p;
    return 0;
}

