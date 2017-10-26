#include <iostream>
#include <string>

using namespace std;

class SantaBag{
public:
    SantaBag();
    SantaBag(string nyr_eigandi, int nyr_hardir, int nyr_mjukir);

    friend ostream& operator << (ostream& outs, const SantaBag &poki);
private:
    int hardirpakkar;
    int mjukirpakkar;
    string eigandi;

};

SantaBag::SantaBag() {
    hardirpakkar = 0;
    mjukirpakkar = 0;
    eigandi = "";
    //cout << "Default constructor" << endl;
}

ostream& operator << (ostream& outs, const SantaBag &poki) {
    outs << "Eigandi: " << poki.eigandi << ", hardir pakkar: ";
    outs << poki.hardirpakkar << ", mjukir pakkar: " << poki.mjukirpakkar;

    return outs;
}

SantaBag::SantaBag(string nyr_eigandi, int nyr_hardir, int nyr_mjukir) {
    hardirpakkar = nyr_hardir;
    mjukirpakkar = nyr_mjukir;
    eigandi = nyr_eigandi;
    //cout << "The other constructor" << endl;
}







int main() {
    SantaBag poki1;
    SantaBag poki2("Stekkjastaur", 5, 7);

    cout << poki1 << endl;
    cout << poki2 << endl;

    return 0;
}
