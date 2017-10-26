#include <iostream>
#include <string>

using namespace std;

class SantaBag{
public:
    SantaBag();
    SantaBag(string nyr_eigandi, int nyr_hardir, int nyr_mjukir);

    friend SantaBag operator + (const SantaBag& lhs, const SantaBag& rhs);

    friend bool operator > (const SantaBag& lhs, const SantaBag& rhs);
    friend bool operator == (const SantaBag& lhs, const SantaBag& rhs);
    friend bool operator < (const SantaBag& lhs, const SantaBag& rhs);
    friend bool operator <= (const SantaBag& lhs, const SantaBag& rhs);

    friend ostream& operator << (ostream& outs, const SantaBag &poki);
    friend istream& operator >> (istream& ins, SantaBag &poki);
private:
    int hardirpakkar;
    int mjukirpakkar;
    string eigandi;

    double value() const;
};

SantaBag::SantaBag() {
    hardirpakkar = 0;
    mjukirpakkar = 0;
    eigandi = "";
    //cout << "Default constructor" << endl;
}

double SantaBag::value() const {
    return hardirpakkar * 1.0 + mjukirpakkar * 0.6;
}

bool operator > (const SantaBag& lhs, const SantaBag& rhs) {
    return (lhs.value() > rhs.value());
}

bool operator == (const SantaBag& lhs, const SantaBag& rhs) {
    return (lhs.value() == rhs.value());
}

bool operator <= (const SantaBag& lhs, const SantaBag& rhs) {
    return !(lhs > rhs);
}

bool operator < (const SantaBag& lhs, const SantaBag& rhs) {
    return !((lhs > rhs) || (lhs == rhs));
}



SantaBag operator + (const SantaBag& lhs, const SantaBag& rhs) {
    SantaBag nyr_poki;

    nyr_poki.hardirpakkar = lhs.hardirpakkar + rhs.hardirpakkar;
    nyr_poki.mjukirpakkar = lhs.mjukirpakkar + rhs.mjukirpakkar;
    nyr_poki.eigandi = lhs.eigandi + " - " + rhs.eigandi;

    return nyr_poki;
}


istream& operator >> (istream& ins, SantaBag &poki) {
    ins >> poki.eigandi >> poki.hardirpakkar >> poki.mjukirpakkar;
    return ins;
}

ostream& operator << (ostream& outs, const SantaBag &poki) {
    if (poki.eigandi == "") {
        outs << "Tomur jolasveinapoki.";
    }
    else {
        outs << "Eigandi: " << poki.eigandi << ", hardir pakkar: ";
        outs << poki.hardirpakkar << ", mjukir pakkar: " << poki.mjukirpakkar;
    }
    return outs;
}

SantaBag::SantaBag(string nyr_eigandi, int nyr_hardir, int nyr_mjukir) {
    hardirpakkar = nyr_hardir;
    mjukirpakkar = nyr_mjukir;
    eigandi = nyr_eigandi;
    //cout << "The other constructor" << endl;
}



int main() {
    int n;
    cin >> n;

    SantaBag *pokar = new SantaBag[n];
    SantaBag bigbag;

    for (int i = 0; i < n; i++) {
        cin >> pokar[i];
        bigbag = bigbag + pokar[i];
    }

    for (int i = 0; i < n; i++) {
        cout << pokar[i] << endl;
    }

    cout << "The total is: " << endl;
    cout << bigbag << endl;



    delete [] pokar;
    return 0;
}



