#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* BuildFromOrderTraversal(node* root) {
    
    cout << "Enter root element : " << endl;
    int data;
    cin >> data;

    root = new node(data);

    //base case
    if(data == -1) {
        return NULL;
    }

    //recursive calls
    cout << "Enter data to insert in left of " << data << endl;
    root->left = BuildFromOrderTraversal(root->left);

    cout << "Enter data to insert in right of " << data << endl;
    root->right = BuildFromOrderTraversal(root->right);

    return root;

}

void LevelOrderTraversal(node* root) {

    queue<node*> q;
    q.push(root);

    q.push(NULL);//serprater

    while(!q.empty()) {

        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else { 
            
            cout << temp->data << " ";

            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void ReverseLevelOrderTraversal(node* root) {

    queue<node*> q;
    vector<int> v;
    stack<int> s;
    q.push(root);

    q.push(NULL);//serprater

    while(!q.empty()) {

        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            v.push_back(-1);
            s.push(-1);
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            
            v.push_back(temp->data);
            s.push(temp->data);

            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }

    cout << "From vector - ";
    for(int i=v.size()-1; i>=0; i--) {
        if(v[i] == -1) {
            cout << endl;
            continue;
        }
        cout << v[i] << " ";
    }

    cout <<"\n\nFrom stack -";
    while(!s.empty()) {
        if(s.top() == -1)
            cout << endl;
        else 
            cout << s.top() << " ";
        
        s.pop();
    }

}

int main() {

    node* root;

    root = BuildFromOrderTraversal(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    cout << "From level order traversal -\n";
    LevelOrderTraversal(root);
    
    ReverseLevelOrderTraversal(root);

    return 0;
}