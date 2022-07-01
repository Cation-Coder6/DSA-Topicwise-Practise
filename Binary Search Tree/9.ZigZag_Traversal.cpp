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


void zigzag(Node *root){
    if(root == nullptr){
        return;
    }
    
    bool momo = 1;
    stack<Node*> curr_level , next_level;
    curr_level.push(root);
    
    
    while(!curr_level.empty()){
        int n = curr_level.size();
        
        for(int i=0;i<n;i++){
            Node *temp = curr_level.top();
            curr_level.pop();
            if(temp){
                cout<<temp->data<<" ";
            
                if(momo){
                    if(temp->left){
                        next_level.push(temp->left);
                    }
                    if(temp->right){
                        next_level.push(temp->right);
                    }
                
                }
                if(!momo){
                    if(temp->right){
                        next_level.push(temp->right);
                    }
                
                    
                    if(temp->left){
                        next_level.push(temp->left);
                    }
                    
                }
            }
            
        }
        if(curr_level.empty()){
            momo = !momo;
            swap(curr_level , next_level);
        }
    }
}

int main(){
    Node* root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right= new Node(10);
    zigzag(root);
    
}