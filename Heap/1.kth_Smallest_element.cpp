#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kth_smallest_element(vector<int> v , int k){
    priority_queue<int> maxh;
    for(int i=0;i<v.size();i++){
        maxh.push(v.at(i));
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    return maxh.top();
}

int main(){
    vector<int> v;
    char s;
    s = 'y';
    while(1){
        cout<<"\nEnter the next element -> ";
        int k;
        cin>>k;
        v.push_back(k);
        cout<<"\nDo you want more elements (Y/N) ->";
        cin>>s;
        if(s=='n' || s=='N')
            break;
    }
    cout<<"\nThe kth smallest element that you want is :- ";
    int k;
    cin>>k;
    cout<<"\nThe "<<k<<"th smallest element in the array is :- "<<kth_smallest_element(v,k)<<endl;
}