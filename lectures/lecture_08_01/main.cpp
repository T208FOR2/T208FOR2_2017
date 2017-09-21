#include <iostream>

using namespace std;

const int N = 4;

void reverse_array(string s[], int n);

int main()
{
    string texti[N];

    for (int i = 0; i < N; i++) {
        cin >> texti[i];
    }

    cout << "------------------" << endl;
    reverse_array(texti, N);

    for (int i = 0; i < N; i++) {
        cout << texti[i] << endl;
    }

    return 0;
}

void reverse_array(string s[], int n) {
    string tmp;
    for (int i = 0; i < n; i++) {
        tmp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = tmp;
    }
}
