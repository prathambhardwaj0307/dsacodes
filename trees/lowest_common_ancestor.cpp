#include <bits/stdc++.h>
using namespace std;

#define print(f) (cout<<f);

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

Node* insertBst(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left = insertBst(root->left,val);
    }
    else{
        root->right = insertBst(root->right ,val);
    }

    return root;
}

Node* lca(Node* root, int n1,int n2){
    if(root==NULL){
        return NULL;
    }

    // if one of them is root then return root
    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* left = lca(root->left,n1,n2);
    Node* right = lca(root->right,n1,n2);

    // if both of them are on one side
    if(left==NULL){
        return right;
    }

    if(right==NULL){
        return left;
    }

    // if both of them are on opposite sides and they are not root
    return root;
}

int main(){
    Node* root = NULL;
    root = insertBst(root,5);
    insertBst(root,1);
    insertBst(root,3);
    insertBst(root,4);
    insertBst(root,2);
    insertBst(root,7);

    print(lca(root,3,2)->data);
    print(endl);
    print(lca(root,4,7)->data);
    print(endl);
    print(lca(root,5,4)->data);
    print(endl);
    print(lca(root,5,7)->data);
    print(endl);

    return 0;
}