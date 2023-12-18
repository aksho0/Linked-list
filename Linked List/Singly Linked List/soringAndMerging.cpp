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

    LinkedList() {
        head = NULL;
    }

    void insertAtTail(int data) {

        node* temp = head;
        node* new_node = new node(data);

        if(head == NULL) {
            head = new_node;
            return;
        }
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display() {

        node* temp = head;
        while(temp != NULL) {
            cout<<temp->val<<"->";
            temp = temp->next;
        }cout<<"NULL"<<endl;
    }

};

node* mergeLinkedList(node* &head1, node* &head2) {

    node* dummyHeadNode = new node(-1);

    node* ptr1 = head1;
    node* ptr2 = head2;
    node* ptr3 = dummyHeadNode;

    while(ptr1 && ptr2) {
        if(ptr1->val > ptr2->val) {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        else {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        ptr3 = ptr3->next;
    }

    if(ptr1) {
        ptr3->next = ptr1;
    } 
    else {
        ptr3->next = ptr2;
    }

    return dummyHeadNode->next;

}


int main() {

    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.display();

    LinkedList ll2;
    ll2.insertAtTail(2);
    ll2.insertAtTail(5);
    ll2.display();

    LinkedList ll3;
    ll3.head = mergeLinkedList(ll1.head, ll2.head);
    ll3.display();

    return 0;
}