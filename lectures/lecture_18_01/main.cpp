#include <iostream>
#include "Numbers.h"

using namespace std;


void printArray(Numbers x) {
    cout << "Printing: ";
    for (int i = 0; i < x.n; i++) {
        cout << x.p[i] << " ";
    }
    cout << endl;
}

int main() {
    Numbers num;

    for (int i = 0; i < 10; i++) {
        num.append(i);
    }

    printArray(num);
    cout << "-----------------" << endl;
    for (int i = 0; i < 5; i++) {
        Numbers tmp;
        tmp = num;
        printArray(tmp);
    }
    return 0;
}
