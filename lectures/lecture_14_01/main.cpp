#include <iostream>
#include <string>

using namespace std;

int main()
{
    string *s;
    int n;
    cin >> n;

    s = new string[n];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // snua vid fylkinu!

    for (int i = 0; i < n; i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    delete [] s;

    return 0;
}
