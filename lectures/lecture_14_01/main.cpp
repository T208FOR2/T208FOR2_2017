#include <iostream>
#include <string>

using namespace std;

void mirror_v1(string *fylki, int fjoldi);
void mirror_v2(string* &fylki, int fjoldi);

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
    mirror_v1(s, n);

    for (int i = 0; i < n; i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    delete [] s;

    return 0;
}

void mirror_v2(string* &fylki, int fjoldi) {
    //
}


void mirror_v1(string *fylki, int fjoldi) {
    string tmp;
    for (int i = 0; i < fjoldi/2; i++) {
        tmp = fylki[i];
        fylki[i] = fylki[fjoldi-i-1];
        fylki[fjoldi-i-1] = tmp;
    }
}
