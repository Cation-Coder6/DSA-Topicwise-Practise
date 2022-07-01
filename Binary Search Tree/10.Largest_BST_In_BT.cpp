#include<iostream>
using namespace std;

class Node {
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

struct info{
    int size;
    int max;
    int min;
    int ans;
    bool is_BST;
};

info largest_bst(Node *root){
    if(root == nullptr)
        return {0,INT_MIN , INT_MAX ,0,1};  
        
    if(root->left == nullptr && root->right == nullptr){
        return {1,root->data , root->data , 1,1};
    }
    
    info lft = largest_bst(root->left);
    info rght = largest_bst(root->right);
    
    info currentNode;
    currentNode.size = 1 + (lft.size + rght.size);
    
    if((lft.is_BST && rght.is_BST) && (lft.max < root->data) && (rght.min > root->data)){
        currentNode.min = min(leftTree.min , min(rightTree.min , root->data));
        currentNode.max = max(rightTree.max , max(leftTree.max , root->data));
                
        currentNode.ans = currentNode.size;
        currentNode.is_BST = true;
                
        return currentNode;
    }
        
        
    return {(lft.size + rght.size +1) , INT_MIN, INT_MAX,max(lft.ans , rght.ans), false};
}

int main(){
    Node *root = new Node(3);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);
    
    cout<<largest_bst(root).ans;
}