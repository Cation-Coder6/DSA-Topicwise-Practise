#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<iterator>
#include<utility>
using namespace std;

void k_most_frequent(vector<int> v){
    unordered_map<int ,int> mp;
    for(int i=0; i<v.size();i++){
        mp[v[i]]++;
    }
    priority_queue<pair<int , int>> maxh;
    for(auto i = mp.begin() ; i != mp.end() ; i++){
    maxh.push({i->second , i->first});

    }
    while(!maxh.empty()){
        cout<<(maxh.top()).second<<" ";
        maxh.pop();
    }
}

int main(){
    vector<int> v = {5,5,5,5,4,3,3,3,3,2,2,4,5,6};
    k_most_frequent(v);
}