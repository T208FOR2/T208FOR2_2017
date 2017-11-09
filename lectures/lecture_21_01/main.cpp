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

    double strength() const;
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
    return (lhs.strength() > rhs.strength());
}

Team operator + (const Team& lhs, const Team& rhs) {
    Team newteam;

    newteam.nafn = lhs.nafn + " - " + rhs.nafn;
    if (lhs.attack > rhs.attack) {
        newteam.attack = lhs.attack;
    }
    else {
        newteam.attack = rhs.attack;
    }

    if (lhs.defence > rhs.defence) {
        newteam.defence = lhs.defence;
    }
    else {
        newteam.defence = rhs.defence;
    }

    newteam.coach = (lhs.coach || rhs.coach);

    return newteam;
}

ostream& operator << (ostream& outs, const Team& t) {
    outs << t.nafn << " (" << t.attack << ", " << t.defence << ")";
    if (t.coach) {
        outs << " with a coach";
    }
    return outs;
}

istream& operator >> (istream& ins, Team& t) {
    int thecoach;
    ins >> t.nafn >> t.attack >> t.defence >> thecoach;
    if (thecoach == 1) {
        t.coach = true;
    }
    else {
        t.coach = false;
    }
    return ins;
}

double Team::strength() const {
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
