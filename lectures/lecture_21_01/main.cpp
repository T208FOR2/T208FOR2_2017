#include <iostream>
#include <string>

using namespace std;

class Team{
public:
    Team();
    Team(string new_nafn, int new_attack, int new_defence, bool new_coach);

    friend bool operator > (const Team& lhs, const Team& rhs);
    friend Team operator + (const Team& lhs, const Team& rhs);

    friend ostream& operator << (ostream& outs, const Team& t);
    friend istream& operator >> (istream& ins, Team& t);

private:
    string nafn;
    int attack;
    int defence;
    bool coach;

    double strength();
};

Team::Team() {
    nafn = "";
    attack = 0;
    defence = 0;
    coach = false;
}

Team::Team(string new_nafn, int new_attack, int new_defence, bool new_coach) {
    nafn = new_nafn;
    attack = new_attack;
    defence = new_defence;
    coach = new_coach;
}

bool operator > (const Team& lhs, const Team& rhs) {
}
Team operator + (const Team& lhs, const Team& rhs) {
}

ostream& operator << (ostream& outs, const Team& t) {
}

istream& operator >> (istream& ins, Team& t) {

}

double Team::strength() {
    if (coach) {
        return (attack*attack + defence*defence)*1.2;
    }
    else {
        return attack*attack + defence*defence;
    }
}


int main() {
    Team Elite("The Elite Team", 90, 85, true);
    Team A, B, C;
    cin >> A >> B;
    C = A + B;
    cout << A << endl << B << endl << C << endl;
    if (C > Elite) {
        cout << C << " is better than the elite team!" << endl;
    }
    return 0;
}
