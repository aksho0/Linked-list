#include<iostream>
using namespace std;

class Queue {
    public:
        int* arr;
        int front;
        int rear;
        int size;
    
    Queue(int s) {
        size = s;
        arr = new int[s];
        this->front = 0;
        rear = 0;
    }

    void push(int elem) {

        if(rear == size) {
            cout << "Queue is full" << endl;
        }
        else {
            arr[rear] = elem;
            rear++;
        }
    }

    void pop() {

        if(this->front == rear) {
            cout << "Queue is empty" << endl;
        }
        else {
            this->front++;

            if(this->front == rear) {
                this->front = 0;
                rear = 0;
            }
        }
    }

    int qfront() {
        
        if(this->front == rear) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else {
            return arr[this->front];
        }
    }

    bool isEmpty() {

        if(this->front == rear) {
            return 1;
        }
        else {
            return 0;
        }

    }
};

int main() {

    Queue q(5);

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