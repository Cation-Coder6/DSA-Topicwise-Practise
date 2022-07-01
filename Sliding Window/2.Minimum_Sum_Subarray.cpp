#include<iostream>
using namespace std;


int main(){
    int n;
    cout<<"Enter the size of the array :- "; cin>>n;
    int a[n];
    cout<<"\nEnter the elements of the array :- ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int x;
    cout<<"\nEnter the minimum sum :-";
    cin>>x;

    int ans = INT_MAX;
    int sum = 0 , i = 1;
    int start = 0 , end = 0;
    while(end<n){
        while(sum<=x && end<n){
            sum+=a[end++];
            i++;
        }
        ans = min(ans , i);
        while(sum>x && start<n){
            sum -= a[start++];
            i--;
        }
        ans = min(ans , i);
    }
    cout<<ans;
}