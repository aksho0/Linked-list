#include<iostream>
using namespace std;

class node {
public:

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
        while(temp) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }cout<<endl;
    }

    void insertAtEnd (int data) {

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

    void deleteHead() {

    if(head == NULL) {
        return;
    }

    node* temp = head;
    head = head->next;
    
    if(head == NULL) {
        tail = NULL;
        return;
    } else {
        head->prev = NULL;
    }
    
    free(temp);
    
    }

    void deleteTail() {

        if(head == NULL) {
            return;
        }

        node* temp = tail;

        tail = tail->prev;
        if(tail == NULL) {
            head = NULL;
            return;
        } else {
            tail->next = NULL;
        }
        free(temp);
    }

    void deleteAtPosition(int k) {

        int count = 1;
        node* temp = head;

        while(count < k) {
            temp = temp->next;
            count++;
        }

        //now temp is pointing to kth node which is going to be deleted 
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);

    }


};

void deleteSameNeighbourNode(node* &head, node* &tail) {

    node* currNode = tail->prev;

    while(currNode != head) {
        node* nextNode = currNode->next;
        node* prevNode = currNode->prev;
        if(prevNode->val == nextNode->val) {
            currNode->next->prev = currNode->prev;
            currNode->prev->next = currNode->next;
            free(currNode);
        }
        currNode = prevNode;
        nextNode = currNode->prev;
        prevNode = prevNode->prev;
    }
}



int main() {

    DoublyLinkedList dl;

    // dl.insertAtEnd(1);
    // dl.insertAtEnd(2);
    // dl.insertAtEnd(3);
    // dl.insertAtEnd(4);
    // dl.insertAtEnd(5);
    // dl.display();

    // dl.deleteHead();
    // dl.display();

    // dl.deleteTail();
    // dl.display();

    // dl.deleteAtPosition(3);
    // dl.display();

    dl.insertAtEnd(2);
    dl.insertAtEnd(1);
    dl.insertAtEnd(1);
    dl.insertAtEnd(2);
    dl.insertAtEnd(1);
    // dl.insertAtEnd(2);
    // dl.insertAtEnd(1);
    dl.display();

    deleteSameNeighbourNode(dl.head, dl.tail);
    dl.display();


    return 0;
}