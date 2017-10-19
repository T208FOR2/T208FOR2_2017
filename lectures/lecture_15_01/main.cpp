#include <iostream>
#include <string>

using namespace std;

class Namskeid {
    public:
        string nafn;
        void prenta();
};

class Student {
    public:
        string nafn;
        string heimilisfang;

        Namskeid uppahaldsfag;

        void set_faedingarar(int ar);
        int get_faedingarar();

        void prenta();

    private:
        int faedingarar;

};


int main()
{
    Namskeid n1, n2;
    n1.nafn = "Forritun";
    n2.nafn = "Staerdfraedi";

    Student s1,s2,s3;
    s1.nafn = "Jon";
    s1.set_faedingarar(1992);
    s1.heimilisfang = "Laugavegur 11";
    s1.uppahaldsfag = n1;

    s2.nafn = "Sigga";
    s2.set_faedingarar(1991);
    s2.heimilisfang = "Kringlan 7";
    s2.uppahaldsfag = n2;

    s1.prenta();
    s2.prenta();

    return 0;
}

void Student::set_faedingarar(int ar) {
    if (ar < 1800) {
        cout << "Sorry, wrong birthyear" << endl;
    }
    else if (ar > 2017) {
        cout << "Sorry, please reapply after you're born" << endl;
    }
    else {
        faedingarar = ar;
    }
}

int Student::get_faedingarar() {
    return faedingarar;
}

void Student::prenta() {
    cout << "Nemandi: " << nafn << " (" << faedingarar << ")";
    cout << " Heimili: " << heimilisfang << endl;
    cout << "Uppahaldsfag: " << uppahaldsfag.nafn << endl;
}

void Namskeid::prenta() {
    cout << nafn;
}


