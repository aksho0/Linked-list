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

node* findMiddleElem(node* &head) {

    //finding middle node with slow fasst approach
    //when the fast ptr reaches at the end of the ll, the slow ptr will be pointing at the middle node 

    node* slow = head;
    node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

bool isPalidrome(node* head) {

    node* slow = head;
    node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node* curr_node = slow->next;
    node* prev_node = slow;
    slow->next = NULL;

    //reversing the linked list
    while(curr_node) {
        node* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    node* head1 = head;
    node* head2 = prev_node;
    while(head2) {
        if(head1->val != head2->val) {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return 1;
    
}

int main() {

    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    //ll1.insertAtTail(3);
    // ll1.insertAtTail(3);
    // ll1.insertAtTail(2);
    ll1.insertAtTail(1);
    ll1.display();

    // node* middleElem = findMiddleElem(ll1.head);
    // cout<<middleElem->val<<endl;

    cout << isPalidrome(ll1.head) << endl;;

    return 0;
}