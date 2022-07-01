#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<set>
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

void parent(Node *root,Node *par , vector<pair<Node *,Node *>> &v){
    if(root == nullptr){
        return;
    }
    else if(par!=nullptr){
        v.push_back(make_pair(root , par));
    }
    parent(root->left , root, v);
    parent(root->right, root ,v);
}

pair<bool,Node*> contain(vector<pair<Node *, Node*>> v , Node *key){
    for(int i=0;i<v.size();i++){
        if(v.at(i).first == key)
            return make_pair(1,v.at(i).second);
    }
    return make_pair(0,nullptr);
}

void NodesAtDistance(Node *root , Node *target , int dist){
    if(root == nullptr){
        return;
    }
    vector<pair<Node *, Node*>> v;
    parent(root , nullptr , v);
    
    set<Node *> visited;
    queue<Node *> q;
    q.push(target);
    int level = 0;
    while(!q.empty()){
        
        int n = q.size();

        for(int i=0;i<n;i++){
            
            Node *temp = q.front();
            q.pop();
            if(level == dist)
                cout<<temp->data<<" ";
            visited.insert(temp);
            
            if(temp->left && visited.find(temp->left) == visited.end())
                q.push(temp->left);
            
            if(temp->right && visited.find(temp->right) == visited.end())
                q.push(temp->right);
            
            pair<bool , Node *> t = contain(v,temp);
            if(t.first && visited.find(t.second) == visited.end())
                q.push(t.second);
        }
        level++;
        cout<<endl;
    }
}
    




int main(){

Node *root = new Node(1);
root->left = new Node(2);

root->right = new Node (3);
root->left->left = new Node(4);

    NodesAtDistance(root , root->left , 1);

}