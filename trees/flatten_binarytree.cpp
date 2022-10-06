#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *right;
    struct Node *left;
    
    Node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void flatten(Node* root){
    if(root==NULL || (root->right==NULL && root->left==NULL)){
        return;
    }

    if(root->left!=NULL){
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right!=NULL){
            t=t->right;
        }

        t->right = temp;
    }

    flatten(root->right);
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);
    
    inorder(root);
    flatten(root);
    inorder(root);
    return 0;
}
