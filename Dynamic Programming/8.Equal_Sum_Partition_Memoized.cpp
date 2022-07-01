#include<iostream>
using namespace std;

int Subset(int a[] , int sum , int n , bool **dp){
    if(n == 0 && sum != 0){
        return dp[n][sum] = false;
    }
    else if(sum == 0){
        return dp[n][sum] = true;
    }
    
    else if(dp[n][sum] != 0)
        return dp[n][sum];
    
    else if(sum >= a[n-1]){
        return dp[n][sum] = (Subset(a , sum , n-1 , dp) || Subset(a , sum-a[n-1] , n-1 , dp));
    }
    else return dp[n][sum] = Subset(a , sum , n-1 , dp);
}

bool EqualPartition(int *a , int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    if(sum%2 != 0){
        return false;
    }
    else {
        bool **dp = new bool*[n+1];
        for(int i = 0; i <= n ; i++){
            dp[i] = new bool[sum+1];
            for(int j = 0; j <= sum ; j++){
                dp[i][j] = 0;
            }
        }
        return Subset(a , sum/2 , n , dp);
    }
}

int main(){
        int ar[] = {1,5,11,5};
    cout<<EqualPartition(ar , 4);
}