#include <iostream>

using namespace std;

class Timi {
    public:
        Timi();

        void set_klst(int new_klst);
        void set_minutur(int new_minutur);

    private:
        int klst;
        int minutur;
};


int main()
{
    Timi t;


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

