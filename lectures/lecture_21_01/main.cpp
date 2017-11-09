#include <iostream>
using namespace std;

struct LinkNode {
    char data;
    LinkNode* next;
};

void printLinkNodes(LinkNode* thenode) {
    while (thenode != NULL) {
        cout << thenode->data << " ";
        thenode = thenode->next;
    }
    cout << endl;
}

void switchPlaces(LinkNode* &thenode) {

    //*** ADD CODE HERE ***


    //*** END OF ADDED CODE ***
}

int main() {
    LinkNode* head = NULL, *tmp;
    char thedata = 'D';
    for (int i = 0; i < 4; i++) {
        tmp = new LinkNode;
        tmp->data = thedata--;
        tmp->next = head;
        head = tmp;
    }
    printLinkNodes(head);
    switchPlaces(head);
    printLinkNodes(head);
    return 0;
}
