#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void open_my_file(ifstream& theinputfile, string thefilename );

int main()
{
    string thefilename, braut;

    string current_braut;
    int ar, karlar, konur;
    bool ekkert_fannst = true;

    thefilename = "hr_bachelor.txt";
    cin >> braut;

    ifstream theinputfile;
    open_my_file(theinputfile, thefilename);

    // Get rid of the first line
    for (int i = 0; i < 4; i++) {
        theinputfile >> current_braut;
    }

    while (theinputfile >> current_braut && theinputfile >> ar && theinputfile >> karlar && theinputfile >> konur) {
        if (current_braut == braut) {
            cout << "Ar: " << ar << ", Fjoldi: " << karlar + konur << endl;
            ekkert_fannst = false;
        }
    }

    theinputfile.close();

    if (ekkert_fannst) {
        cout << "Sorry, couldn't find anything matching " << braut << endl;
    }

    return 0;
}

void open_my_file(ifstream& theinputfile, string thefilename ) {
    theinputfile.open( thefilename.c_str() );
    if (theinputfile.fail()) {
        cout << "Can't open the file: " << thefilename << endl;
        exit(1);
    }
}
