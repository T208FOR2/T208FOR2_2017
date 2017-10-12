#include <iostream>

using namespace std;

int main() {
    int thesize = 2, n = 0;
    int *p = new int[thesize];

    int tala;
    cin >> tala;
    while (tala >= 0) {
        // Setja inn i fylkid p...

        cin >> tala;
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    delete [] p;
    return 0;
}

