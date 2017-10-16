#include <iostream>

using namespace std;

int** create_2d_array(int& rows, int& columns);
void delete_2d_array(int** a, int rows);

void transpose_2d_array(int **&a, int& rows, int& columns);

void swap_values(int& a, int& b);

int main() {
    int rows, columns;
    cin >> rows >> columns;

    int **p = create_2d_array(rows, columns);

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

int** create_2d_array(int& rows, int& columns) {
    int** a = new int*[rows];
    for (int i = 0; i < rows; i++) {
        a[i] = new int[columns];
    }
    return a;
}

void delete_2d_array(int **a, int rows) {
    for (int i = 0; i < rows; i++) {
        delete [] a[i];
    }
    delete [] a;
}

void transpose_2d_array(int **&a, int& rows, int& columns) {
    int **a_bylt = create_2d_array(columns, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            a_bylt[j][i] = a[i][j];
        }
    }

    delete_2d_array(a, rows);

    a = a_bylt;

    swap_values(rows, columns);
}

void swap_values(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}
