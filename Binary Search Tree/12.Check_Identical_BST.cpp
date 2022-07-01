#include<iostream>
#include<stack>

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


bool isIdentical(Node *root1 , Node *root2){
    if(root1 == nullptr && root2 == nullptr){
        return 1;
    }
    else if(root1 == nullptr || root2 == nullptr){
        return 0;
    }
     
    bool condtn1 = (root1->data == root2->data);
    bool condtn2 = isIdentical(root1->left , root2->left);
    bool condtn3 = isIdentical(root1->right , root2->right);
    
    return (condtn1 && condtn2 && condtn3);
}




void insert(Node *&root, int val){
    if(root == nullptr){
        root = new Node(val);
        return;
    }
    else if(val<root->data){
        insert(root->left,val);
    }
    else if(val>root->data){
        insert(root->right , val);
    }
}


int main(){
     Node * root = NULL;
    insert(root, 5);
    insert(root, 4);
    insert(root, 3);
    insert(root, 2);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    
    Node * root1 = NULL;
    insert(root1, 5);
    insert(root1, 4);
    insert(root1, 3);
    insert(root1, 2);
    insert(root1, 1);
    insert(root1, 6);
    insert(root1, 7);
    
    cout<<isIdentical(root , root1);
    
    return 0;
}