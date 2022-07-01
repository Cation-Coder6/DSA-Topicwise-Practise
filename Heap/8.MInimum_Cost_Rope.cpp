#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {3,5,1,2,6};
    priority_queue<int , vector<int> , greater<int>> minh;
    for(int i=0;i<v.size();i++){
        minh.push(v[i]);
    }
    int sum1 = 0;
    while(minh.size() != 1){
        int a = minh.top();
        minh.pop();
        int b = minh.top();
        minh.pop();
        int sum = a + b;
        sum1+=sum;
        minh.push(sum);
    }
    cout<<"The minimum cost could be :- "<<sum1<<endl;
}