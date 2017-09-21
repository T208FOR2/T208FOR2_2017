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

    for (int i = 0; i < N; i++) {
        cout << texti[i] << endl;
    }

    return 0;
}

void reverse_array(string s[], int n) {

}
