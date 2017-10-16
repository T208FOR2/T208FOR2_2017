#include <iostream>

using namespace std;

void transpose_2d_array(int **&a, int& rows, int& columns);
int** create_2d_array(int& rows, int& columns);
void delete_2d_array(int** a, int rows);

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
    int **p_bylt = create_2d_array(columns, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            p_bylt[j][i] = a[i][j];
        }
    }

    delete_2d_array(p, rows);

    p = p_bylt;

    int tmp = rows;
    rows = columns;
    columns = tmp;
}
