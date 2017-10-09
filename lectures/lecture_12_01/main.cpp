#include <iostream>
#include <cmath>

using namespace std;

const int NUM = 100;

int main()
{
    int n, sum = 0;
    int fylki[NUM];
    double sigma = 0, mean;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> fylki[i];
        sum += fylki[i];
    }
    mean = static_cast<double>(sum)/n;

    for (int i = 0; i < n; i++) {
        //sigma += pow(fylki[i] - mean, 2);
        sigma += (fylki[i] - mean)*(fylki[i] - mean);
    }

    sigma = sqrt( sigma / (n-1));

    cout << "The average " << static_cast<double>(sum)/n << endl;
    cout << "StdDev: " << sigma << endl;

    return 0;
}
