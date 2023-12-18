#include<iostream>
using namespace std;

class node {
    public:

    int val;
    node* next;

    node(int elem) {
        val = elem;
        next = NULL;
    }
};

class Stack{
    public :
       node* top;
       node* head;

    Stack() {
        top = NULL;
        head = NULL;
    }

    void push(int elem) {

        node* new_node = new node(elem);

        if(top == NULL) {
            top = new_node;
            head = new_node;
            return;
        }

        top->next = new_node;
        top = new_node;

    }

    void pop() {
        
        if(top == NULL) {
            cout << "Stack underflow" << endl;
        }
        else if(top == head) {
            node* temp = head;

            head = NULL;
            top = NULL;

            delete temp;
        }
        else {

            node* temp = head;

            while(temp->next &&temp->next != top) {
                temp = temp->next;
            }

            node* del = temp->next;
            top = temp;

            delete del;
        }
    }

    int peek() {
        
        if(top == NULL) {
            return -1;
        }
        else {
            return top->val;
        }
    }

    bool isEmpty() {
        
        if(top == NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }
        
};

int main() {

    Stack st;

    st.push(1);
    st.push(2);

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    // cout << st.isEmpty() << endl;


    return 0;
}