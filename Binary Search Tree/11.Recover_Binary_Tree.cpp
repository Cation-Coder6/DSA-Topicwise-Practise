z#include<iostream>
#include<stack>
#include<vector>
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

vector<Node*> inorder(Node *root){
    vector<Node*> v;
    if(root == nullptr){
        return v;
    }
    Node *temp = root;
    stack<Node *> s;
    
    while( temp || !s.empty()){
        while(temp){
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        v.push_back(temp);
        temp = temp->right;
    }
}


int main(){
    
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);
    vector<Node *> v = inorder(root);
    
    for(int i=0;i<v.size()-1;i++){
        cout<<v.at(i)->data<<" ";
        }

    
    cout<<"\n";
    for(int i=0;i<v.size()-1;i++){
        Node *temp = v.at(i);
        Node *temp1 = v.at(i+1);
        if(temp->data > temp1->data){
            //cout<<temp->data<<" "<<temp1->data;
            int a = temp1->data;
            int j = i+1;
            while(j<v.size()-1){
                if(a>v.at(j)->data)
                    break;
                    j++;
            }
            //cout<<v.at(j)->data;
            swap(v.at(i)->data , v.at(j)->data);
        }
    }
    for(int i=0;i<v.size()-1;i++){
        cout<<v.at(i)->data<<" ";
        }
}