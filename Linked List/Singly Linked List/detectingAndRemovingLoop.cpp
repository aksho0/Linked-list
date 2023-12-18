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

node* detectLoop(node* head) {
    
    if(head == NULL && head->next == NULL) {
        return NULL;
    } 


    auto slow = head;
    auto fast = head;

    //this condtion will get satisfied if slow == head
    while(fast && slow) { 

        fast = fast->next;
        if(fast == NULL) {
            return NULL;
        }
        else {  
            fast = fast->next;
        }

        slow = slow->next;

        if(slow == NULL) { 
            return NULL;
        }

        //slow and fast will meet at somewhere in the loop
        //if they meet then cycle is present
        if(slow == fast) { 
            return slow;
        }
    }

    return NULL;
}

node* startingOfLoop(node* head) {

    if(head == NULL) {
        return NULL;
    }
    
    node* intersection = detectLoop(head);
    
    //if loop is not there then there is no need to move forward
    //we'll simply return NULL in this case
    if(intersection == NULL) {
        return NULL;
    }
    node* temp = head;

    //we'll start moving forward temp from the head and intersection from the intersection point of slow and fast
    //they will met at some point viz the starting point if the loop
    //they will meet because the distance from head to the start of loop and
    //the distance from the intersection to the start is same
    while(intersection != temp) {
        temp = temp->next;
        intersection = intersection->next;
    }

    return intersection;
}

void removeLoop(node* &head) {

    if(head == NULL) {
        return;
    }
    
    auto startOfLoop = startingOfLoop(head);
    auto temp = startOfLoop;

    //if temp->next == startOfLoop then it is the starting point if the loop
    //bz temp was initially at the same place where the startOfLoop pointer is
    while(temp->next != startOfLoop) {
        temp = temp->next;
    }  

    temp->next = NULL;

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

    node* temp = ll.head;

    // //traversing to the last node
    // while(temp->next != NULL) {
    //     temp = temp->next;
    // }

    // //creating loop
    // temp->next = ll.head->next->next;

    if(detectLoop(ll.head) != NULL) {
        cout << "Loop is present at " << startingOfLoop(ll.head)->val << endl;
    }
    else {
        cout << "Loop is not present" << endl;
    }

    removeLoop(ll.head);

    if(detectLoop(ll.head) != NULL) {
        cout << "Loop is present at " << startingOfLoop(ll.head)->val << endl;
    }
    else {
        cout << "Loop is not present" << endl;
        ll.display();
    }
    

    return 0;
}