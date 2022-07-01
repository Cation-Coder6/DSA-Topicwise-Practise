#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


Node *LCA(Node *root, int n1, int n2){
    if(root == nullptr){
        return nullptr;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node *lft = LCA(root->left,  n1,  n2);
    Node *rght = LCA(root->right,n1, n2);
    
    if(lft && rght){
        return root;
    }
    else if(lft)
        return lft;
    return rght;
}


int height(Node *root , int val, int dist){
    if(root == nullptr){
        return -1;
    }
    else if(root->data == val){
        return dist;
    }
    int lft = height(root->left, val, dist+1);
    if(lft != -1)
        return lft;
    return height(root->right, val , dist+1);
}

int shortest_Distance(Node *root , int n1 , int n2){
    Node *lca = LCA(root , n1 , n2);
    
    int dist_left = height(lca,n1,0);
    int dist_right = height(lca,n2,0);
    
    return (dist_left + dist_right);
}


int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    
    cout<<shortest_Distance(root , 4,7);
}