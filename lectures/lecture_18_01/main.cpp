#include <iostream>

using namespace std;

class Numbers {
public:
    Numbers();
    ~Numbers();

    void append(int i);

    int *p;

    int n;
    int max_elements;

private:

    void double_size_of_array();
};

Numbers::Numbers() {
    cout << "***** CONSTRUCTOR ******" << endl;
    p = NULL;
    n = 0;
    max_elements = 0;
}

Numbers::~Numbers() {
    cout << "***** DESTRUCTOR ******" << endl;

    if (p != NULL) {
        cout << "----------- DELETE" << endl;
        delete [] p;
        p = NULL;
    }
}

void Numbers::append(int i) {
    if (n == max_elements) {
        double_size_of_array();
    }
    p[n] = i;
    n = n+1;
}

void Numbers::double_size_of_array() {
    cout << "****** double size ******" << endl;
    if (max_elements == 0) {
        max_elements = 2;
        cout << "----------- NEW" << endl;
        p = new int[max_elements];
    }
    else {
        max_elements = max_elements * 2;
        cout << "----------- NEW" << endl;
        int *new_p = new int[max_elements];
        for (int i = 0; i < n; i++) {
            new_p[i] = p[i];
        }
        cout << "----------- DELETE" << endl;
        delete [] p;
        p = new_p;
    }
}

void printArray(Numbers num) {
    for (int i = 0; i < num.n; i++) {
        cout << num.p[i] << endl;
    }
}

int main() {
    Numbers num;

    for (int i = 0; i < 10; i++) {
        num.append(i);
    }

    printArray(num);

    return 0;
}
