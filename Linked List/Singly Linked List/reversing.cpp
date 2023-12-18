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

class LinkedList{

public :

    node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtTail(int data) {

        node* new_node = new node(data);
        node* temp = head;

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
        }cout << "NULL" << endl;
    }

    void reversePrint(node* head) {

        //base case
        if(head == NULL) {
            return;
        }

        //recursive case 
        reversePrint(head->next);
        cout<<head->val<<" ";
    }

};

node* reverseLL(node* &head) {

    node* curr_node = head;
    node* prev_node = NULL;

    //move all three pointers one step ahead
    while(curr_node != NULL) {
        node* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    //when this loop end , prev_node will be pointiong to my last node which is new head
    node* new_head = prev_node;
    return new_head;
}

node* revreseLLrecursion(node* &head) {

    //base case
    if(head || head->next) {
        return head;
    }
    
    //recursive case
    node* new_head = revreseLLrecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return new_head;
}



int main() {

    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();

    cout<<"Reversing the values while traversing through the list -\n";
    ll.reversePrint(ll.head);
    cout<<endl;    

    cout<<"Reversing the linked list itself -\n";
    ll.head = reverseLL(ll.head);
    ll.display();

    cout<<"Reversing the linked list itself through recursion -\n";
    ll.head = revreseLLrecursion(ll.head);
    ll.display();

    return 0;
}