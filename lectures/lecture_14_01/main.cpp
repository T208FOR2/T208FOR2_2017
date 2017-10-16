#include <iostream>

using namespace std;

int** create_2d_array(int& rows, int& columns);
void delete_2d_array(int** a, int rows);

void read_2d_array(int** a, int rows, int columns);
void print_2d_array(int** a, int rows, int columns);

void transpose_2d_array(int **&a, int& rows, int& columns);

void swap_values(int& a, int& b);

int main() {
    int rows, columns;
    cin >> rows >> columns;

    int **p = create_2d_array(rows, columns);
    read_2d_array(p, rows, columns);

    cout << "-------------------" << endl;

    print_2d_array(p, rows, columns);

    cout << "-------------------" << endl;

    transpose_2d_array(p, rows, columns);
    print_2d_array(p, rows, columns);

    cout << "-------------------" << endl;

    delete_2d_array(p, rows);

    return 0;
}

void read_2d_array(int** a, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> a[i][j];
        }
    }
}

void print_2d_array(int** a, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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

    swap_values(rows, columns);
    a = a_bylt;
}

void swap_values(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}
