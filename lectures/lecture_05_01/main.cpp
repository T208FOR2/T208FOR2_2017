#include <iostream>

using namespace std;

double x_i_nta_veldi(double x, int n);

int main()
{
    double x;
    int n;
    double nidurstada;

    cin >> x >> n;

    nidurstada = x_i_nta_veldi(x,n);

    cout << x << " to the power of " << n << " is " << nidurstada << endl;

    return 0;
}

double x_i_nta_veldi(double x, int n) {
    double result = x;
    for (int i = 0; i < n; i++) {
        result = result * x;
    }
    return result;
}



