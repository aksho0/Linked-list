#include<iostream>
using namespace std;

class node{
    public :
        int val;
        node* next;

        node(int data) {
            val = data;
            next = NULL;
        }

};

void display(node* &head) {
    node* temp = head;
    while(temp != NULL) {
        cout<<temp->val<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void insertHead(node* &head, int data) {
    node* new_node = new node(data);
    new_node->next = head;
    head = new_node;
}

void insertTail(node* &head, int data) {

    node* new_node = new node(data);
    node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    //here temp is at the last postion or at the tail
    temp -> next = new_node; 

}

void insertAtPositon(node* &head, int data, int pos) {

    if(pos == 0) {
        insertHead(head, data);
        return;
    }
    node* temp = head;
    node* new_node = new node(data);
    int cur_position = 0;

    while(cur_position != (pos-1)) {
        temp = temp -> next;
        cur_position++;
    }
    
    //here temp is pointing to node at pos-1
    new_node->next = temp->next;
    temp->next = new_node;

}

void upgradeVal(node* &head, int data, int k) {

    node* temp = head;
    int curr_pos = 0;

    while(curr_pos != k) {
        temp = temp->next;
        curr_pos++;
    }

    //temp is pointing to kth node
    temp->val = data;
}

void deleteHead(node* &head) {

    node* temp = head;
    head = head->next;
    free(temp);
}

void deleteTail(node* &head) {

    node* second_last = head;

    while(second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    //here second_last node is pointing to the second last node
    node* temp = second_last->next; //node to be deleted
    second_last->next = NULL;
    free(temp); 

}

void deleteAtPostion(node* &head, int pos) {

    if(pos == 0) {
        deleteHead(head);
        return;
    }

    int curr_pos = 0;
    node* prev = head;

    while(curr_pos != (pos-1)) {
        prev = prev->next;
        curr_pos++;
    } 

    //prev is pointing to node at pos-1
    node* temp = prev->next;//node to be deleted
    prev->next = prev->next->next;
    free(temp);
}

int main() {

    node* head = NULL;
    cout<<"Orignal node - \n";
    display(head);
    
    cout<<"\nNode after inserting two values at the start - \n";
    insertHead(head, 20);
    display(head);
    insertHead(head, 10);
    display(head);

    cout<<"\nNode after inserting two values at the end - \n";
    insertTail(head, 30);
    display(head);
    insertTail(head, 50);
    display(head);

    cout<<"\nNode after inserting two values at the kth postion viz 3rd postion - \n";
    insertAtPositon(head, 40, 3);
    display(head);

    cout<<"\nNode after upgrading value at postion 2nd - \n";
    upgradeVal(head, 33, 2);
    display(head);

    cout<<"\nNode after deleting value at the start - \n";
    deleteHead(head);
    display(head);

    cout<<"\nNode after deleting value at the end - \n";
    deleteTail(head);
    display(head);

    cout<<"\nNode after deleting value at kth postion viz 1st positon - \n";
    deleteAtPostion(head, 1);
    display(head);

    return 0;
}