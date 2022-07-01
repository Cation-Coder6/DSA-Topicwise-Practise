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

Node *buildtree(int *postorder , int *inorder, int start , int end){
    static int index = end;
    if(start>end){
        return nullptr;
    }
    int curr = postorder[index];
    Node *root = new Node(curr);
    int pos = search(inorder,start,end,curr);
    index--;
    
    if(start == end){
        return root;
    }
    root->right = buildtree(postorder , inorder , pos+1, end);
    root->left = buildtree(postorder , inorder , start , pos-1);
    
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
    int a[] = {4,2,5,3,1};
    int b[] = {4,2,1,5,3};
    Node *root = buildtree(a,b,0,4);
    preorder_traversal(root);
    
}
