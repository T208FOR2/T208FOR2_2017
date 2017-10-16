#include <iostream>

using namespace std;

int main() {
    int *x = NULL;

    for (int i = 0; i < 0x223234; i++) {
        x++;
    }

    cout << x << endl;
    cout << *x << endl;

    return 0;


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
        for (int j = 0; j < columns; j++) {
            p_bylt[j][i] = p[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        delete [] p[i];
    }
    delete [] p;

    p = p_bylt;
    int tmp = rows;
    rows = columns;
    columns = tmp;


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-------------------" << endl;

    for (int i = 0; i < rows; i++) {
        delete [] p[i];
    }
    delete [] p;

    return 0;
}
