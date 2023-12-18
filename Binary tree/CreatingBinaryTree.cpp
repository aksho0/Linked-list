#include<iostream>
#include<queue>
using namespace std;

// not done 

class node {
    public:
        int data;
        node* right;
        node* left;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class tree{
public:

    node* root;

    tree(int val) {
        root->data = val;
        root->left = NULL;
        root->right = NULL;
    }

    node* BiuldTree(node* root) {
    
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
        root->left = BiuldTree(root->left);

        cout << "Enter data to insert in right of " << data << endl;
        root->right = BiuldTree(root->right);

        return root;
    }

    void LevelOrderTraversal() {

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


};

int main() {

    tree* t;

    node* root;

    //creating a tree
    root = t->BiuldTree(root);

    t->LevelOrderTraversal();

    return 0;
}