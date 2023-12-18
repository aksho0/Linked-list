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
        }
        cout<<"NULL"<<endl;
    }
 
};

void deleteAlternateNode(node* &head) {

    node* curr_node = head; 
    while(curr_node != NULL && curr_node->next != NULL) {
        node* temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
    }

}

void deleteDuplicates(node* &head) {

    node* curr_node = head;

    while(curr_node) {
        while((curr_node->next) && (curr_node->val == curr_node->next->val)) {
            node* temp = curr_node->next;
            curr_node->next = curr_node->next->next;
            free(temp);
        }
        curr_node = curr_node->next;
    }
}

void removeKthNodeFromEnd(node* &head, int k) {

    node* ptr1 = head;
    node* ptr2 = head;

    //move ptr2 from k steps ahead
    while(k--) {
        ptr2 = ptr2->next;
    }

    //SPECIAL CASE
    if(ptr2 == NULL) { // here k is equal to lenght of linked list
    //means we have to delete head node

    node* temp = head;
    head = head->next;
    free(temp);

    }
    
    //ptr2 is kth steps ahead of ptr1
    //when pt2 is at null(end of the list), ptr1 will be at node to be deleted
    while(ptr2->next != NULL) { //so we uused ptr2->next to reach at the previous node to be deleted
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    //now pt1 is pointing to the node before kth node from the end
    node* temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    free(temp);
}


int main() {

    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(6);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.display();

    // deleteAlternateNode(ll.head);
    // ll.display();

    // deleteDuplicates(ll.head);
    // ll.display();

    removeKthNodeFromEnd(ll.head, 3);
    ll.display();

    return 0;
}