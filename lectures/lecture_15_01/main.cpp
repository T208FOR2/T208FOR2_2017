#include <iostream>
#include <string>

using namespace std;

struct Namskeid {
    string nafn;
};

struct Student {
    string nafn;
    int faedingarar;
    string heimilisfang;

    Namskeid uppahaldsfag;
};


int main()
{
    Namskeid n1, n2;
    n1.nafn = "Forritun";
    n2.nafn = "Staerdfraedi";

    Student s1,s2,s3;
    s1.nafn = "Jon";
    s1.faedingarar = 1992;
    s1.heimilisfang = "Laugavegur 11";
    s1.uppahaldsfag = n1;

    return 0;
}


