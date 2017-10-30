#include "Numbers.h"

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

Numbers::Numbers( const Numbers& cloneme ) {
    cout << "***** COPY CONSTRUCTOR ******" << endl;
    n = cloneme.n;
    max_elements = cloneme.max_elements;
    if (max_elements == 0) {
        p = NULL;
    }
    else {
        p = new int[max_elements];
        for (int i = 0; i < n; i++) {
            p[i] = cloneme.p[i];
        }
    }
}

void Numbers::operator = ( const Numbers& sameasme ) {
    cout << "***** ASSIGNMENT OPERATOR ******" << endl;
    if (max_elements != sameasme.max_elements) {
        if (p != NULL) {
            delete [] p;
        }
        p = new int[max_elements];
        max_elements = sameasme.max_elements;
    }

    n = sameasme.n;
    for (int i = 0; i < n; i++) {
        p[i] = sameasme.p[i];
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
