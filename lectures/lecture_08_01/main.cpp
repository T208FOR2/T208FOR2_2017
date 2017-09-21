#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void open_my_file(ifstream& theinputfile, string thefilename );

int main()
{
    string thefilename;
    cin >> thefilename;

    ifstream theinputfile;
    open_my_file(theinputfile, thefilename);

    theinputfile.close();
    cout << "Thanks!" << endl;

    return 0;
}

void open_my_file(ifstream& theinputfile, string thefilename ) {
    theinputfile.open( thefilename.c_str() );
    if (theinputfile.fail()) {
        cout << "Can't open the file: " << thefilename << endl;
        exit(1);
    }
}
