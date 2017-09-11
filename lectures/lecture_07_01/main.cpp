#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream theinputfile;
    int x;

    theinputfile.open("/Users/eyjo/Desktop/randomtolur.txt"); // MAC
//    theinputfile.open("c:\\Users\\eyjo\\Desktop\\randomtolur.txt");  // WINDOWS

    theinputfile >> x;

    theinputfile.close();

    cout << "The first number is: " << x << endl;

    return 0;
}
