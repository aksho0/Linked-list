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

    void insertAtStart(int data) {

        node* new_node = new node(data);

        if(head == NULL) {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
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

    void insertAtPosition(int data, int k) {

        node* new_node = new node(data);
        node* temp = head;
        int counter = 1;

        while(counter < (k-1)) {
            temp = temp->next;
            counter++;
        }

        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next->prev = new_node;
        return;

    }
};

int main() {

    DoublyLinkedList dl;
    
    dl.insertAtStart(3);
    dl.insertAtStart(2);
    dl.insertAtStart(1);
    dl.diaplay();

    dl.insertAtEnd(5);
    dl.diaplay();

    dl.insertAtPosition(4,4);
    dl.diaplay();

    return 0;
}