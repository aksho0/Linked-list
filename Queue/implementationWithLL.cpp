#include<iostream>
using namespace std;

class node {
    public:

    int val;
    node* next;

    node(int data) {
        val = data;
        next = NULL;
    }
};

class Queue {
    public:
        node* front;
        node* rear;
    
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void push(int elem) {

        node* new_node = new node(elem);

        if(rear == NULL) {
            // this is the first element in ll
            rear = new_node;
            front = new_node;
            return;
        }
        else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void pop() {

        if(rear == NULL) {
            cout << "Queue is empty" << endl;
        }
        else {
            node* temp = front;
            front = front->next;

            delete temp;
        }
    }

    int qfront() {
        
        if(front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else {
            return front->val;
        }
    }

    bool isEmpty() {

        if(this->front == NULL) {
            return 1;
        }
        else {
            return 0;
        }

    }
};

int main() {

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.pop();
    cout << q.qfront() << endl;
    
    q.pop();
    cout << q.qfront() << endl;
    
    q.pop();
    cout << q.qfront() << endl;
    
    q.pop();
    cout << q.qfront() << endl;

    q.pop();
    cout << q.qfront() << endl;
    
    
    if(q.isEmpty()) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}