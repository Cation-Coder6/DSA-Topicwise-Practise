#include<iostream>
using namespace std;

bool Subset(int *a , int n , int sum){
    if(n == 0 && sum != 0){
        return false;
    }
    else if(sum == 0)
        return true;
        
        else if(sum>=a[n-1])
            return (Subset(a , n-1 , sum-a[n-1]) || Subset(a , n-1 , sum));
        else 
            return Subset(a , n-1 , sum);
}

bool EqualSum(int *a , int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    if(sum%2 != 0)
        return false;
    else return Subset(a , n , sum/2);
}


int main(){
    int ar[] = {1,5,11,5};
    cout<<EqualSum(ar , 4 );
}