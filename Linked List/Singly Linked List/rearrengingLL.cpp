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

node* rotateByK(node* &head, int k) {

    //1.find length
    node* tail = head;
    int n = 0;

    while(tail->next) {
        n++;
        tail = tail->next;
    }
    n++;//for including last node

    //2.find tail and asssign tail->next = head
    tail->next = head;

    if(k > n) {
        k = k%n;
        if(k == 0) {
            return head;
        }
    }

    //3.traverse through LL to (k-n)th node
    int count = k-n;
    node* temp = head;
    while(count) {
        temp = temp->next;
        count--;
    } 
    //temp is now pointing to (k-n)th node

    node* new_head = temp->next;
    temp->next = NULL;

    return new_head;

}

node* reorderLL(node* &head) {

    node* ans = head;
    //1. finding the middle element
    node* fast = head;
    node* slow = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    //now slow is pointing to middle element

    node* curr_node = slow->next;
    slow->next = NULL;//seperating the LL 
    node* prev_node = slow;
    
    
    //2.rearrenging the LL from the middle
    while(curr_node) {
        node* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    //3.merging the two halves of the LL
    node* head1 = head;//for LL 1st half
    node* head2 = prev_node;//for LL 2nd half

    while(head1 != head2) {
        node* temp = head1->next;
        head1->next = head2;
        head1 = head2;
        head2 = temp;
    }

    return ans;
}

int main() {

    LinkedList ll;

    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();

    //not working
    // ll.head = rotateByK(ll.head, 3);
    // ll.display();

    ll.head = reorderLL(ll.head);
    ll.display();

    return 0;
}