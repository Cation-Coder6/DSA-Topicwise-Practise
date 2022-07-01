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

int search(int *inorder, int start, int end, int key){
    int i = start;
        while(inorder[i]!=key)
            i++;
            return i;
}


Node *buildtree(int *preorder, int *inorder, int start , int end){
    static int index = 0;
    if(start>end){
        return nullptr;
    }
    
    int curr = preorder[index];
    Node *node = new Node(curr);
    int v = search(inorder,start,end,curr);
    
    index++;
   
    
    if(start == end){
        return node;
    }
    
    
    
    node->left = buildtree(preorder, inorder , start , v-1);
    node->right = buildtree(preorder, inorder, v+1, end);
}

void preorder_traversal(Node *root){
    if(root == nullptr){
        return;
    }
   cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main(){
    int a[] = {1,2,4,3,5};
    int b[] = {4,2,1,5,3};
    Node *root = buildtree(a,b,0,4);
    preorder_traversal(root);
    
}