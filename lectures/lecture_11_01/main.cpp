#include <iostream>

using namespace std;

int main()
{
    unsigned int pos;
    string inputline = " VIDEO: Elements of the #DoD and @FEMA are providing humanitarian relief for #PuertoRico and #USVI.";

    pos = inputline.find("#");
    cout << inputline << endl;
    cout << pos << endl;

    return 0;
}
