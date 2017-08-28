#include <iostream>

using namespace std;

int main()
{
    const double PI = 3.1415926;
    int i = 0;
    int n,N;

    while (i <= 100) {

        if (!((i % 3 == 0) || (i % 7 == 0))) {
            cout << i << endl;
        }


        i = i + 1;
        i += 1;
        i++;
    }


    return 0;
}
