#include<iostream>
using namespace std;

class CircularQ{
public:

    int *arr;
    int front; 
    int rear;
    int size;

    CircularQ(int s) {
        size = s;
        arr = new int[s];
        front = rear = -1;
    }

    void push(int elem) {
        
        
        if((rear == size-1 && front == 0) || rear == (front - 1) % (size - 1)) {
            cout << "Queue is full" << endl;
            return;
        }
        else if(front == -1) {
            // its the first element 
            front = rear = 0;
            arr[rear] = elem;
        }
        else if(rear == size-1 && front != 0) {
            //front is somewhere in middle of the array nd rear is at the end
            //so we can push element fron the start
            rear = 0;
            arr[rear] = elem;
        }
        else {
            //normal flow
            rear++;
            arr[rear] = elem;
        }
    }

    void pop() {
        if(front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        else if(front == rear) {
            //there is single element int the array
            front = rear = -1;
        }
        else if(front == size-1 && rear != 0) {
            //to maintain cyclic nature
            //means front is at the end of the array so we put front at the start again
            front = 0;
        }
        else {
            //normal flow
            front++;
        }
    }

    int qfront() {

        if(front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {

        if(front == -1) {
            return 1;
        }

        return 0;

    }

};

int main() {

    CircularQ cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);

    cout << cq.qfront() << endl;
    cq.pop();

    cout << cq.qfront() << endl;
    cq.pop();

    cq.push(4);

    cout << cq.qfront() << endl;
    cq.pop();
    cq.pop();
    cq.pop();

    cout << cq.qfront() << endl;

    return 0;
}