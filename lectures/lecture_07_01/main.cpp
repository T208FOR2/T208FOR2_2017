#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream theinputfile;
    int x;

    theinputfile.open("/Users/eyjo/Desktop/randomtolur.txt"); // MAC
//    theinputfile.open("c:\\Users\\eyjo\\Desktop\\randomtolur.txt");  // WINDOWS

    if ( theinputfile.fail() ) {
        cout << "Could not open the file!" << endl;
        exit(1);
    }

    theinputfile >> x;

    theinputfile.close();

    cout << "The first number is: " << x << endl;

    return 0;
}
