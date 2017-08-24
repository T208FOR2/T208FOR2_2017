#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool elvishasarrived = false;

    string nafn;
    int i = 0;
    while (i <= 10) {
        cout << "Please write a name: ";
        cin >> nafn;

        if (nafn == "Elvis") {
            elvishasarrived = true;
        }

        i += 1;
    }

    if ( elvishasarrived ) {
        cout << "Elvis has arrived!" << endl;
    }
    else {
        cout << "Nope, didn't see Elvis." << endl;
    }

    return 0;
}
