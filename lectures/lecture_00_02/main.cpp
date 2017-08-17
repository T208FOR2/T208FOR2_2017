#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "How many hellos? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Hello!" << endl;
    }

    return 0;
}
