#include<iostream>
using namespace std;

class node {

public:

    int val;
    node* prev;
    node* next;

    node(int data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {

public :

    node* head;
    node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void diaplay() {

        node* temp = head;
        while(temp != NULL) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }cout<<endl;
    }

    void insertAtEnd(int data) {

        node* new_node = new node(data);

        if(tail == NULL) {
            tail = new_node;
            head = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

};

void reverseDLL(node* &head, node* &tail) {

    node* currPtr = head;
    while(currPtr) {
        node* nextPtr = currPtr->next;
        currPtr->next = currPtr->prev;
        currPtr->prev = currPtr;
        currPtr = nextPtr;
    }

    node* new_head = tail;
    tail = head;
    head = new_head;

}

int main() {

    DoublyLinkedList dl;
    
    dl.insertAtEnd(1);
    dl.insertAtEnd(2);
    dl.insertAtEnd(3);
    dl.insertAtEnd(4);
    dl.insertAtEnd(5);
    dl.diaplay();

    reverseDLL(dl.head, dl.tail);
    dl.diaplay();

    return 0;
}