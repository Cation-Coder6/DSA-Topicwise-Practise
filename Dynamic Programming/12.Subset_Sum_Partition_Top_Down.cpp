#include<iostream>
using namespace std;

int main(){
    int ar[] = {2,3,5,6,8,10};
    int n = 6;
    int sum = 10;
    
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j = 0; j<sum+1;j++){
            if(i == 0 && j!= 0)
                t[i][j] = 0;
            else if(j == 0){
                t[i][j] = 1;
            }
        }
    }
    
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum ; j++){
            if(j>=ar[i-1]){
                t[i][j] = t[i-1][j-ar[i-1]] +t[i-1][j];
            }
            else 
                t[i][j] = t[i-1][j];
        }
    }
    
    cout<<t[n][sum];
}