#include <iostream>

using namespace std;

const int NUM = 10;

int main() {
    string texti[NUM], keyword = "";

    for (int i = 0; i < NUM; i++) {
        cin >> texti[i];
    }

    cout << "What word are you looking for? ";
    cin >> keyword;
    while (keyword != "quit") {

        int index = -1;
        for (int i = 0; i < NUM; i++) {
            if (keyword == texti[i]) {
                index = i;
            }
        }

        if (index >= 0) {
            cout << "The word" << keyword << " is number ";
            cout << index << " in the list" << endl;
        }
        else {
            cout << "Sorry, couldn't find the word " << keyword << endl;
        }

        cout << "What word are you looking for? ";
        cin >> keyword;
    }


    return 0;
}
