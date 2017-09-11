#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream theinputfile;

    theinputfile.open("/Users/eyjo/Desktop/randomtolur.txt"); // MAC
    theinputfile.open("c:\\Users\\eyjo\\Desktop\\randomtolur.txt");  // WINDOWS

    return 0;
}
