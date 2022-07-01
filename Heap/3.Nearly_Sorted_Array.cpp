#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> sort_nearly_sorted(vector<int> v , int k){
    priority_queue<int , vector<int> , greater<int>> minh;
    vector<int> a;
    for(int i = 0 ; i < v.size() ; i++){
        minh.push(v[i]);
        if(minh.size()>k){
            a.push_back(minh.top());
            minh.pop();
        }
    }
    while(minh.size()){
        a.push_back(minh.top());
        minh.pop();
    }
    return a;
}
int main()
{
    vector<int> v = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        cout<<"\n";
    v = sort_nearly_sorted(v , k);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}