#include<iostream>
using namespace std;

class node {

public :

    int val;
    node* next;

    node(int data) {
        val = data;
        next = NULL;
    }
};

class LinkedList {

public :

    node* head;

    LinkedList(){
        head = NULL;
    }

    void display() {

        node* temp = head;
        while(temp != NULL) {
            cout<<temp->val<<"->";
            temp = temp->next;
        }cout<<"NULL\n";
    }

    void insertAtTail(int data) {

        node* new_node = new node(data);
        
        if(!head) {
            head = new_node;
            return;
        }

        node* temp = head;
        
        while(temp->next) {
            temp = temp->next;
        }

        temp->next = new_node;

    }
};

node* oddEvenLL(node* &head) {

    if(!head) {
        return head;
    }
    
    node* evenHead = head->next;
    node* oddptr = head;
    node* evenptr = evenHead;

    while(evenptr && evenptr->next) {
        oddptr->next = oddptr->next->next;
        evenptr->next = evenptr->next->next;
        oddptr = oddptr->next;
        evenptr = evenptr->next;
    }

    oddptr->next = evenHead;

    return head;
}

int main() {

    LinkedList ll;

    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    //ll.insertAtTail(6);
    ll.display();

    ll.head = oddEvenLL(ll.head);
    ll.display();

    return 0;
}