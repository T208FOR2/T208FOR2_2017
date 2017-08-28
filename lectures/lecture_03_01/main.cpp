#include <iostream>

using namespace std;

int main()
{
    int i = 0;

    while (i <= 100) {

        if ((i % 3 == 0) && (i % 7 == 0)) {
            cout << i << endl;
        }


        i = i + 1;
    }


    return 0;
}
