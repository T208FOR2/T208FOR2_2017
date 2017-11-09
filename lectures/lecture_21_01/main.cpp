#include <iostream>
using namespace std;
class Dummy {
public:
    Dummy(int k);
    Dummy(const Dummy& cloneme);

    ~Dummy();

    void operator = (const Dummy& sameasme);
    int *p;
    int n;
};

Dummy::Dummy(int k) {
    p = new int[k];
    n = k;
}

Dummy::Dummy(const Dummy& cloneme) {
    n = cloneme.n;
    p = new int[n];
    for (int i = 0; i < n; i++) {
        p[i] = cloneme.p[i];
    }
}

void Dummy::operator = (const Dummy& sameasme) {

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
