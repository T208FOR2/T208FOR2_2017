#include <iostream>

using namespace std;

int testfall(int tala, bool& is_cubed);

int main()
{
    int a;
    bool is_cubed = false;
    cin >> a;

    cout << "------------------" << endl;
    cout << a << endl;
    cout << testfall(a, is_cubed) << endl;
    cout << a << endl;
    cout << "------------------" << endl;

    if (is_cubed) {
        cout << "the number you wrote is some other number to the power of three" << endl;
    }

    return 0;
}


int testfall(int tala, bool& is_cubed) {
    bool tempnidurstada = false;
    for (int i = 0; i < tala; i++) {
        if (i*i*i == tala) {
            tempnidurstada = true;
        }
    }
    is_cubed = tempnidurstada;

    tala = tala + 1;
    return tala;
}



