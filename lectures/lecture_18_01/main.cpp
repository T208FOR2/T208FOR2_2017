#include <iostream>

using namespace std;

class Numbers {
public:
    Numbers();

private:
    int *p;

    int n;
    int max_elements;

    void double_size_of_array();
};

Numbers::Numbers() {
    cout << "***** CONSTRUCTOR ******" << endl;
    p = NULL;
    n = 0;
    max_elements = 0;
}

void Numbers::double_size_of_array() {
    cout << "****** double size ******" << endl;
    if (max_elements == 0) {
        max_elements = 2;
        p = new int[max_elements];
    }
    else {
        max_elements = max_elements * 2;
        int *new_p = new int[max_elements];
        for (int i = 0; i < n; i++) {
            new_p[i] = p[i];
        }
        delete [] p;
        p = new_p;
    }
}

int main() {

    return 0;
}
