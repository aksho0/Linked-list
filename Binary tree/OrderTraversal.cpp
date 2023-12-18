#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node {
    public:
        int data;
        node* right;
        node* left;

    node(int d) {
        data = d;
        right = NULL;
        left = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter data -\n";
    int data;
    cin >> data;

    root = new node(data);

    //base case
    if(data == -1) {
        return NULL;
    }

    //recurcive case
    cout<<"Enter data for inserting in the left of " << data << endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;

}

void levelOrderTraversal(node* root) {
    
    queue<node*> q;

    q.push(root);
    q.push(NULL);

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

//L N R
//node will get printed after traversing left and then after printing it will traverse to right
void inOrderTraversal(node* root) {

    //base case
    if(root == NULL) {
        return;
    }

    //call for left node
    inOrderTraversal(root->left);
    
    //printing the current node
    cout << root->data << " ";
    
    //call fro right node
    inOrderTraversal(root->right);

}

//L R N
//post means, node will get printed after the traversal
void postOrderTraversal(node* root) {

    //base case
    if(root == NULL) {
        return;
    }

    //call for left node
    postOrderTraversal(root->left);

    //call fro right node
    postOrderTraversal(root->right);

    //printing the current node
    cout << root->data << " ";

}

// N L R
//pre means, node will get printed first then it will traverse
void preOrderTraversal(node* root) {

    //base case
    if(root == NULL) {
        return;
    }

    //printing the current node
    cout << root->data << " ";

    //call for left node
    preOrderTraversal(root->left);

    //call fro right node
    preOrderTraversal(root->right);


}

//NOT WORKING
void POtraveral(node* root) {

    node* temp = root;

    queue<node*> q;

    while(temp) {
        node* t = temp;
        q.push(temp);

        temp = temp->left;
        t = t->right;

        while(temp->left) {
            q.push(temp);
            temp = temp->left;
        } 
        while(t->right) {
            q.push(t);
            t = t->right;
        }
    }

    while(!q.empty()) {
        cout << q.front()->data << " ";
        q.pop();
    }

}



int main() {

    node* root;
    //creating a tree
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    cout << "Level in order traversal -" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "In order traversal -" << endl;
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre order traversal -" << endl;
    preOrderTraversal(root);
    cout << endl;

    cout << "Post order traversal -" << endl;
    postOrderTraversal(root);
    cout << endl;

    // cout << "Pre order traversal from itration -" << endl;
    // POtraveral(root);
    // cout << endl;

    return 0;
}