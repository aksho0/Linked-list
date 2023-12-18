#include<iostream>
using namespace std;

//push back
//push front
//pop back
//pop front

class DoublyEndedQ {
    public:
        int* arr;
        int front;
        int rear;
        int size;

    DoublyEndedQ(int s) {
        size = s;
        arr = new int[s];
        front = -1;
        rear = -1;
    }

    void push_front(int elem) {

        if(rear == size-1 && front == 0) {
            //q is full;
            cout << "Queue is full" << endl;
            return;
        }
        else if(front == -1) { 
            //its the first element
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1) {
            //front is at first idx so inorder to maintain circular flow
            //we put front at the end
            front = size-1;
        }
        else {
            //normal flow
            front--;
        }

        arr[front] = elem;
    }

    void push_back(int elem) {

        if(rear == size-1 && front == 0) {
            cout << "Queue is full" << endl;
            return;
        }
        else if(rear == -1) {
            //its the first element
            rear = front = 0;
        }
        else if((rear == size-1)  && (front != 0)) {
            //here rear is at the end of array so in order to maintain circular flow
            //we placed rear at the begining
            rear = 0;
        }
        else {
            //normal flow
            rear++; 
        }

        arr[rear] = elem;
    }

    void pop_front() {
        
        if(front == -1) {
            cout << "Queue is empty" << endl;
        }
        else if((front == size -1) && (rear != 0)) {
            //here front is at the end so we put front at the begining
            //in order to maintain circular flow
            front = 0;
        }
        else if(front == 0 && rear == 0) {
            //means there is only one element present in there array
            front = rear = -1;
        }
        else {
            //normal flow
            front++;
        }
    }

    void pop_back() {
        if(rear == -1) {
            cout << "Queue is empty" << endl;
        }
        else if((rear ==  0) && (front != size -1)) {
            //to maintain circular flow
            rear = size -1;
        }
        else if(front == 0 && rear == 0) {
            front = rear = -1;
        }
        else {
            rear--;
        }
    }

    int qfront() {

        if(front == -1) {
            //queue is empty
            return -1;
        }
        return arr[front];
    }

    int qback() {

        if(rear == -1) { 
            return -1;
        }

        return arr[rear];
    }
};

int main() {

    DoublyEndedQ dq(2);

    dq.push_front(12);
    dq.push_back(14);

    cout << dq.qfront() << endl;
    cout << dq.qback() << endl;

    dq.pop_front();

    cout << dq.qfront() << endl;
    cout << dq.qback() << endl;

    dq.pop_back();

    cout << dq.qfront() << endl;

    return 0;
}