#include <iostream>

using namespace std;

void get_input(int& a, int& b);

int main()
{
    int a,b;
    get_input(a,b);



    return 0;
}

void get_input(int& a, int& b) {
    cin >> a >> b;
}
