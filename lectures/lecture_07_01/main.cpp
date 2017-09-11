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
