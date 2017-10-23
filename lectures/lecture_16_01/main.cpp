#include <iostream>

using namespace std;

class Timi {
    public:
        Timi();

        void set_klst(int new_klst);
        void set_minutur(int new_minutur);
        int get_klst() { return klst; };  // inline version for short functions
        int get_minutur() {return minutur; };

    private:
        int klst;
        int minutur;
};


int main()
{
    Timi t;

    t.set_klst(4543);
    t.set_minutur(-345359);

    if (t.get_klst() < 10) {
        cout << "0";
    }
    cout << t.get_klst() << ":" << t.get_minutur() << endl;


    return 0;
}


Timi::Timi() {
    klst = 0;
    minutur = 0;
    cout << "Constructor: Timi()" << endl;  // Debug info
}

void Timi::set_klst(int new_klst) {
    klst = new_klst;
}

void Timi::set_minutur(int new_minutur) {
    minutur = new_minutur;
}

