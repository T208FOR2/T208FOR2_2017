#include <iostream>

using namespace std;

struct Dagsetning {
    int ar;
    int manudur;
    int dagur;
    string vikudagur;
};

Dagsetning move_to_next_week(Dagsetning d);

void prenta_dagsetning(Dagsetning d);

int main()
{
    Dagsetning d1;

    d1.ar = 1999;
    d1.manudur = 12;
    d1.dagur = 24;
    d1.vikudagur = "Sunnudagur";

    prenta_dagsetning(d1);

    d1 = move_to_next_week(d1);

    prenta_dagsetning(d1);

    return 0;
}

Dagsetning move_to_next_week(Dagsetning d) {
    Dagsetning tmp = d;
    // pretend all months have 30 days!
    tmp.dagur += 7;
    if (tmp.dagur > 30) {
        tmp.dagur -= 30;
        tmp.manudur++;
    }
    if (tmp.manudur > 12) {
        tmp.manudur -= 12;
        tmp.ar++;
    }
    return tmp;
}

void prenta_dagsetning(Dagsetning d) {
    cout << d.dagur << "/" << d.manudur << "/" << d.ar;
    cout << " (" << d.vikudagur << ")" << endl;
}
