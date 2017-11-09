#include <iostream>

using namespace std;

void towersofhanoi(int n, int source, int intermediate, int destination, int& moves) {
    if (n > 0) {
        towersofhanoi(n-1, source, destination, intermediate, moves);
        cout << "Move " << moves++ << ": Disk " << n << " is moved from tower ";
        cout << source << " to tower " << destination << endl;
        towersofhanoi(n-1, intermediate, source, destination, moves);
    }
}


int main() {
    int n, moves = 1;
    cin >> n;

    towersofhanoi(n, 1, 2, 3, moves);

    return 0;
}
