#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_CHARS = 500;

int main()
{
    ifstream theinputfile;
    char current;
    int n = 0;

    theinputfile.open("/Users/eyjo/Desktop/grimm.txt"); // MAC

    if ( theinputfile.fail() ) {
        cout << "Could not open the file!" << endl;
        exit(1);
    }

    while ( !theinputfile.eof() && n < MAX_CHARS ) {
        current = theinputfile.get();
        cout << current;
        n++;
    }

    theinputfile.close();

    cout << endl;

    return 0;
}
