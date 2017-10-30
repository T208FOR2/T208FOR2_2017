#include <iostream>

using namespace std;

class Numbers {
public:
    Numbers();

private:
    int *p;

    int n;
    int max_elements;
};

Numbers::Numbers() {
    cout << "***** CONSTRUCTOR ******" << endl;
    p = NULL;
    n = 0;
    max_elements = 0;
}

int main() {

    return 0;
}
