#include <iostream>
using namespace std;

int main()
{
    int tala;
    cin >> tala;

    if ( tala % 2 == 0 ) {
        cout << "The number " << tala << " is even." << endl;
    }
    else {
        cout << "The number " << tala << " is odd." << endl;
    }

    return 0;
}
