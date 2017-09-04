#include <iostream>

using namespace std;

double x_i_nta_veldi(double& x, int& n);


int main()
{
    double tala;
    int veldisvisir;
    double nidurstada;

    cin >> tala >> veldisvisir;

    nidurstada = x_i_nta_veldi(tala, veldisvisir);

    cout << tala << " to the power of " << veldisvisir << " is " << nidurstada << endl;

    return 0;
}

double x_i_nta_veldi(double& x, int& n) {
    double result = x;
    for (int i = 0; i < n-1; i++) {
        result = result * x;
    }
    return result;
}



