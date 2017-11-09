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
};

int main() {

    return 0;
}
