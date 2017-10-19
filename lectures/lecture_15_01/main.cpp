#include <iostream>

using namespace std;

struct Dagsetning {
    int ar;
    int manudur;
    int dagur;
    string vikudagur;
};


int main()
{
    Dagsetning d;

    cin >> d.ar >> d.manudur >> d.dagur >> d.vikudagur;

    cout << d.dagur << "/" << d.manudur << "/" << d.ar << " (" << d.vikudagur << ")" << endl;


    return 0;
}


