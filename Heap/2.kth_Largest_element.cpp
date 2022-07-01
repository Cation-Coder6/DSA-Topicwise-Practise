#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kth_largest_element(vector<int> v , int k){
    priority_queue<int , vector<int> , greater<int>> minh;
    for(int i=0;i<v.size();i++){
        minh.push(v.at(i));
        if(minh.size() > k){
            minh.pop();
        }
    }
    return minh.top();
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
    cout<<"\nThe kth largest element that you want is :- ";
    int k;
    cin>>k;
    cout<<"\nThe "<<k<<"th largest element in the array is :- "<<kth_largest_element(v,k)<<endl;
}