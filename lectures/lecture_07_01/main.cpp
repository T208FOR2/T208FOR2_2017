#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream theinputfile;
    int x, sum = 0, n = 0;

    theinputfile.open("/Users/eyjo/Desktop/randomtolur.txt"); // MAC
//    theinputfile.open("c:\\Users\\eyjo\\Desktop\\randomtolur.txt");  // WINDOWS

    if ( theinputfile.fail() ) {
        cout << "Could not open the file!" << endl;
        exit(1);
    }

    while (theinputfile >> x) {
        sum += x;
        n++;
    }

    theinputfile.close();

    cout << "The last number is: " << x << endl;
    cout << "The sum is: " << sum << endl;
    cout << "The number of numbers is: " << n << endl;
    cout << "The average is: " << static_cast<double>(sum) / n << endl;

    return 0;
}
