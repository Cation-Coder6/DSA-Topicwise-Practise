#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void k_closest_number(vector<int> v , int k , int key){
    priority_queue<pair<int , int>> p;
    
    for(int i = 0 ; i < v.size() ; i++){
            int temp = abs(v[i] - key);
            if(temp>0)
            p.push(make_pair(temp , v[i]));
            if(p.size()>k)
                p.pop();
    }
    cout<<"The closest element to the number "<<key<<" are :-";
    while(!p.empty()){
        pair<int , int> temp = p.top();
        cout<<temp.second<<" ";
        p.pop();
    }
}

int main(){
    vector<int> ar = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int k = 4;
    int key = 35;
    k_closest_number(ar , k , key);
}