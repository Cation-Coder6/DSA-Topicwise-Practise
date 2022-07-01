#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<iterator>
using namespace std;

void k_most_frequent(vector<int> v , int k){
    unordered_map<int ,int> mp;
    for(int i=0; i<v.size();i++){
        mp[v[i]]++;
    }
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> minh;
    for(auto i = mp.begin() ; i != mp.end() ; i++){
    minh.push({i->second , i->first});
        if(minh.size()>k)
            minh.pop();
    }
    while(!minh.empty()){
        cout<<(minh.top()).second<<" ";
        minh.pop()
    }
}

int main(){
    vector<int> v = {1,1,1,2,3,2,4,}
    int k = 2;
    k_most_frequent(v , k);
}