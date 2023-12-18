#include<iostream>
using namespace std;

class Stack{
    public :
        int* arr;
        int top;
        int size;

    Stack(int s) {
        this->size = s;
        arr = new int[s];
        top = -1;
    }

    void push(int elem) {

        if(top < size) {
            top++;
            arr[top] = elem; 
        }
        else {
            cout << "Stack overflow" << endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout << "Stack underflow" << endl;
        }
    }

    int peek() {
        if(top >= 0) {
            return arr[top];
        }
        else {
            return -1;
        }
    }

    bool isEmpty() {
        if(top >= 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
        
};

int main() {

    Stack st(3);

    st.push(0);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);



    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();



    return 0;
}