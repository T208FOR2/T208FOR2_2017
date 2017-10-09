#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ord, setning;
    unsigned int pos;
    bool word_appears = false, word_appears_multiple_times = false;

    cin >> ord;
    getline(cin, setning);
    setning = setning.substr(1,setning.length());

    pos = setning.find(ord);
    if (pos < setning.length()) {
        word_appears = true;
        pos = setning.find(ord, pos+1);

        if (pos < setning.length()) {
            word_appears_multiple_times = true;
        }
    }

    if (word_appears) {
        cout << "The word appears";
        if (word_appears_multiple_times) {
            cout << " multiple times";
        }
        cout << "." << endl;
    }
    else {
        cout << "The word doesn't appear in the sentence." << endl;
    }


    return 0;
}

