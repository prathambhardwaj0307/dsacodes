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

void leftView(Node* root){
    if(root==NULL){
        return;
    }

    queue <Node*> q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node *curr = q.front();
            q.pop();

            if(i==0){
                cout<<curr->data<<' ';
            }

            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    } 
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    leftView(root);
    
    cout<<endl;

    struct Node* root2 = new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->left->left=new Node(4);
    root2->left->left->left=new Node(5);
    root2->left->left->left->left=new Node(6);
    leftView(root2);
    return 0;
}
