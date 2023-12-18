#include<iostream>
using namespace std;

class node {
public :
    int val;
    node* prev;
    node* next;

    node(int data) {
        val = data;
        next = NULL;
        prev = NULL;
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

    void display() {
        node* temp = head;
        while(temp != NULL) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }cout<<endl;
    }

    void insertAtTail(int data) {

        node* new_node = new node(data);
        
        if(tail == NULL) {
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

};

bool isPalidrome(node* head, node* tail) {

    while(head != tail && tail != head->prev) {
        if(head->val != tail->val) {
            return 0;
        }
        head = head->next;
        tail = tail->prev;
    }
    return 1;
}

int main() {

    DoublyLinkedList dl;
    dl.insertAtTail(1);
    dl.insertAtTail(2);
    dl.insertAtTail(3);
    dl.insertAtTail(3);
    //dl.insertAtTail(4);
    dl.insertAtTail(2); 
    dl.insertAtTail(1);
    dl.display();

    cout<<isPalidrome(dl.head, dl.tail);

    return 0;
}