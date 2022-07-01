#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"\nEnter the number of elements of the array :- ";
    cin>>n;
    
    int a[n];
    cout<<"\nEnter the elements of the array :- ";
    for(int i = 0;i < n; i++){
        cin>>a[i];
    }
    
    int k;
    cout<<"\nEnter the size of the subarray :- ";
    cin>>k;
    
    int sum = 0;
    for(int i = 0;i < k; i++){
        sum+=a[i];
    }
    
    int ptr1 , ptr2 = 0;
    
    int flag = 0;
    for(ptr1 = 0 , ptr2 = k-1; ptr2 < n; ptr1++ , ptr2++){
        if(sum%3==0){
            flag =1;
            break;
        }
            
        sum+=a[ptr2+1]; 
        sum -= a[ptr1];
    }
    if(flag == 1)
        cout<<"\nSubarray found";
    else
        cout<<"\nSubarray not found";
    
    return 0;
    
}