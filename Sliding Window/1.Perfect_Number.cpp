#include<iostream>
#include<cmath>
using namespace std;

int isperfect(int n){
    int sum = 1;
    for(int i=2;i<sqrt(n);i++){
        if(n%i == 0){
            if(i == n/i)
                sum+=i;
            else
                sum+=i + n/i;
        }
    }
    if(sum == n && n!=1)
        return 1;
    else 
        return 0;
}

int main(){
    int n;
    cout<<"\nEnter the number of elements in the array :- ";
    cin>>n;
    
    int a[n];
    cout<<"\nEnter the elements of the array :- ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int k;
    cout<<"\nEnter the size of the subarray :- "; 
    cin>>k;
    
    for(int i=0;i<n;i++){
        a[i] = isperfect(a[i]);
    }
    
    int sum = 0;
    for(int i=0;i<k;i++){
        sum += a[i];
    }
    int ptr1 , ptr2 = 0;
    
    int max_sum = sum;
    for(ptr1 = 0 , ptr2 = k; ptr2 < n; ptr1++ , ptr2++){
        sum+=a[ptr2]; 
        sum -= a[ptr1];
        if(max_sum<sum)
            max_sum = sum;
    }
    
    cout<<"\nThe maximum number of perfect numbers in the given size of subarrays is :- "<<max_sum;
}
// 28 2 3 6 496 99 8128 24