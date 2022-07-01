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


bool Checker(Node *root , Node *min = nullptr , Node *max = nullptr){
    if(root == nullptr){
        return 1;
    }
    if(min != nullptr && root->data <= min->data){
        return 0;
    }
    if(max != nullptr && root->data >= max->data){
        return 0;
    }
    
    return (Checker(root->left , min, root) && Checker(root->right , root , max));
}


int main(){
    Node* root1 = new Node(5);
    root1->left = new Node(2);
    root1->right = new Node(8);
    
    cout<<Checker(root1, nullptr , nullptr);
}