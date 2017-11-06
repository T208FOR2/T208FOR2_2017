#include <iostream>

using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};

ListNode* search_list(ListNode *head, int value) {
    ListNode *current = head;
    if (current == NULL) {
        return NULL;
    }

    while (current->data != value && current->next != NULL) {
        current = current->next;
    }

    if (current->data == value) {
        return current;
    }
    else {
        return NULL;
    }
}

void insert_into_linked_list(ListNode* afterme, int value) {
    ListNode *new_node = new ListNode;
    new_node->data = value;

    new_node->next = afterme->next;
    afterme->next = new_node;
}

void delete_from_linked_list(ListNode* delete_after_me) {
    ListNode* tmp = delete_after_me->next;
    delete_after_me->next = delete_after_me->next->next;

    delete tmp;
}

int main()
{
    ListNode *head = NULL;

    head = new ListNode;
    head->data = 42;
    head->next = NULL;

    for (int i = 0; i < 10; i++) {
        ListNode *tmp = new ListNode;
        tmp->data = i;
        tmp->next = head;  // (1)
        head = tmp;  // (2)
    }

    // Print out the list
    ListNode *current = head;
    while (current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }

    current = search_list(head, 7);
    if (current != NULL) {
        insert_into_linked_list(current, 17);
    }
    else {
        cout << "Sorry, not found" << endl;
    }
    current = search_list(head, 9);

    delete_from_linked_list(current);

    cout << "--------------------" << endl;

    current = head;
    for (int i = 0; i < 4; i++) {
        current = current->next;
    }

    ListNode *newnode = new ListNode;
    newnode->data = 999;

    newnode->next = current->next;
    current->next = newnode;


    current = head;
    while (current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }

    while (head != NULL) {
        current = head;
        head = head->next;
        delete current;
    }

    return 0;
}
