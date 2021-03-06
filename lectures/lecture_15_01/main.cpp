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
        Student();
        Student(string n);
        Student(string n, string h, int ar);

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

    Student s1,s2,s3, s4("John", "101 Broadway", 1999), s5("Mary");

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
    s3.prenta();
    s4.prenta();
    s5.prenta();


    return 0;
}

Student::Student(string n) {
    cout << "I'M THE THIRD CONSTRUCTOR!!!" << endl;

    nafn = n;
    faedingarar = 2000;
    heimilisfang = "no address";

    Namskeid tomt = {"no course"};
    uppahaldsfag = tomt;
}


Student::Student(string n, string h, int ar) {
    cout << "I'M THE OTHER CONSTRUCTOR!!!" << endl;

    nafn = n;
    heimilisfang = h;
    faedingarar = ar;

    Namskeid tomt = {"no course"};
    uppahaldsfag = tomt;
}


Student::Student() {
    cout << "I'M THE CONSTRUCTOR!!!" << endl;

    nafn = "no name";
    faedingarar = 2000;
    heimilisfang = "no address";

    Namskeid tomt = {"no course"};
    uppahaldsfag = tomt;
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


