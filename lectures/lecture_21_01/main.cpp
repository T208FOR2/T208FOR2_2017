#include <iostream>
using namespace std;
class Dummy {
public:
    Dummy(int k); ~Dummy();
    int *p;
    int n;
};

Dummy::Dummy(int k) {
    p = new int[k];
    n = k;
}

Dummy::~Dummy() {
    delete [] p;
}
void testfunction(Dummy d) {
    for (int i = 0; i < d.n; i++) {
        cout << d.p[i] << endl;
    }
}

int main() {
    Dummy x(10);
    for (int i = 0; i < 10; i++) {
        cin >> x.p[i];
    }
    testfunction(x);
    return 0;
}
