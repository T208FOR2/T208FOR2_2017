#include <iostream>
#include <string>

using namespace std;

int main() {
    int a[10];
    int *p = a;

    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }

    cout << "---------" << endl;

    for (int i = 0; i < 10; i++) {
        cout << p[i] << endl;
    }


    return 0;
}

