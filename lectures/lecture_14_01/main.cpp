#include <iostream>

using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;

    int **p = new int*[rows];
    for (int i = 0; i < rows; i++) {
        p[i] = new int[columns];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> p[i][j];
        }
    }

    cout << "-------------------" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-------------------" << endl;

    int **p_bylt = new int*[columns];
    for (int j = 0; j < columns; j++) {
        p_bylt[j] = new int[rows];
    }




    for (int i = 0; i < rows; i++) {
        delete [] p[i];
    }
    delete [] p;

    return 0;
}
