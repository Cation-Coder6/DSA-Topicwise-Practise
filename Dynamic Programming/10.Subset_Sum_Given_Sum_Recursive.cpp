#include<iostream>
using namespace std;

int Subset(int a[] , int n , int sum){
    if(n == 0 && sum != 0)
        return 0;
        
    else if(sum == 0)
        return 1;
    
    else if(sum>=a[n-1])
        return Subset(a , n-1 , sum - a[n-1]) + Subset(a , n-1 , sum);
    
    else 
        return Subset(a , n-1 , sum);
}

int main(){
    int ar[] = {2,3,5,6,8,10};
    int sum = 10;
    
    cout<<Subset(ar , 6 , sum);
}