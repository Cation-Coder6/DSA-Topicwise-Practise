#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

void k_closest_points(vector<pair<int , int>> a , int k){
    priority_queue<pair<int,pair<int,int>>> mh;
    for(int i=0;i<a.size();i++){
        int temp = ((a[i].first*a[i].first) + (a[i].second*a[i].second));
        mh.push(make_pair(temp , a[i]));
        if(mh.size()>k)
            mh.pop();
    }
    
    while(!mh.empty()){
        cout<<((mh.top()).second).first<<" , "<<((mh.top()).second).second<<"\n";
        mh.pop();
    }
}

int main(){
    vector< pair <int,int> > vect;

    for (int i=0; i<4; i++){
        int a , b;
        cin>>a>>b;
        vect.push_back( make_pair(a , b) );
    }
    int k = 3;
    k_closest_points(vect , k);
    
}