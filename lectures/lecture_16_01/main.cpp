#include <iostream>

using namespace std;

class Timi {
    public:
        Timi();

        void set_klst(int new_klst);
        void set_minutur(int new_minutur);
        int get_klst() { return klst; };  // inline version for short functions
        int get_minutur() {return minutur; };

        void prenta();
    private:
        int klst;
        int minutur;

        void fix_klst();
        void fix_minutur();
};


int main()
{
    Timi t;

    t.set_klst(0);
    t.set_minutur(90);

    t.prenta();

    return 0;
}


Timi::Timi() {
    klst = 0;
    minutur = 0;
    cout << "Constructor: Timi()" << endl;  // Debug info
}

void Timi::prenta() {
    if (klst < 10) {
        cout << "0";
    }
    cout << klst << ":" << minutur << endl;
}


void Timi::set_klst(int new_klst) {
    klst = new_klst;

    fix_klst();
}

void Timi::set_minutur(int new_minutur) {
    minutur = new_minutur;

    fix_minutur();
    fix_klst();
}

void Timi::fix_klst() {
    while (klst < 0) {
        klst += 24;
    }
    while (klst >= 24) {
        klst -= 24;
    }
}

void Timi::fix_minutur() {
    while (minutur < 0) {
        minutur += 60;
        klst--;
    }
    while (minutur >= 60) {
        minutur -= 60;
        klst++;
    }
}
