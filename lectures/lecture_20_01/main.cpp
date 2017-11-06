#include <iostream>

using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};

void print_reverse(ListNode *current) {
    if (current == NULL) {
        return;
    }
    else {
        print_reverse(current->next);
        cout << current->data << endl;
    }
}

int main()
{
    ListNode *head = NULL, *tmp;

    for (int i = 0; i < 10; i++) {
        tmp = new ListNode;
        tmp->data = i;
        tmp->next = head;
        head = tmp;
    }

    tmp = head;
    while (tmp != NULL) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
    cout << "-------------------" << endl;
    print_reverse(head);

    while (head != NULL) {
        tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}
