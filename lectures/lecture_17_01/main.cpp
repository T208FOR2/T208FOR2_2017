#include <iostream>
#include <string>

using namespace std;

class SantaBag{
public:
    SantaBag();
    SantaBag(string nyr_eigandi, int nyr_hardir, int nyr_mjukir);

private:
    int hardirpakkar;
    int mjukirpakkar;
    string eigandi;

};

SantaBag::SantaBag() {
    hardirpakkar = 0;
    mjukirpakkar = 0;
    eigandi = "";
}

SantaBag::SantaBag(string nyr_eigandi, int nyr_hardir, int nyr_mjukir) {
    hardirpakkar = nyr_hardir;
    mjukirpakkar = nyr_mjukir;
    eigandi = nyr_eigandi;
}







int main() {
    SantaBag poki1;


    return 0;
}
