#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(stack<int> &s , int k){
    if(s.empty()){
        s.push(k);
        return;
    }
    int x = s.top();
    s.pop();
    insert_at_bottom(s , k);
    s.push(x);
    
}

void reverse(stack<int> &s){
        if(s.empty())
            return;
            
        int k = s.top();
        s.pop();
        reverse(s);
        insert_at_bottom(s , k);
}

void printer(stack<int> s){
    cout<<"The reversed stack is as follows :- ";    
    while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        
}

int main(){
    int n;
    cout<<"Enter the number of elements in the stack :- ";
    cin>>n;
    stack<int> s;
    cout<<"\n Enter the elements of the array:- ";
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        s.push(k);
    }
    reverse(s);
    printer(s);
}