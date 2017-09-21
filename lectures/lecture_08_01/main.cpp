#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    string thefilename;
    cin >> thefilename;

    ifstream theinputfile;
    theinputfile.open( thefilename.c_str() );
    if (theinputfile.fail()) {
        cout << "Can't open the file: " << thefilename << endl;
        exit(1);
    }



    theinputfile.close();
    cout << "Thanks!" << endl;

    return 0;
}
