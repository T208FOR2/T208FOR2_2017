#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const string KEY_WORD = "apple";

int main()
{
    ifstream theinputfile;
    string current_word;
    int n = 0;

    theinputfile.open("/Users/eyjo/Desktop/grimm.txt"); // MAC

    if ( theinputfile.fail() ) {
        cout << "Could not open the file!" << endl;
        exit(1);
    }

    while (theinputfile >> current_word) {
        if (current_word == KEY_WORD) {
            n++;
        }
    }

    theinputfile.close();

    cout << "The word \"" << KEY_WORD << "\" appears " << n << " times." << endl;

    return 0;
}
