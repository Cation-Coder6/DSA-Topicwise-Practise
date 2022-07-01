#include<iostream>
using namespace std;
int main(){
    int wt[] = { 1, 3, 4, 5 };
    int val[] = { 1, 4, 5, 7 };
    int n = 4;
    int w = 10;

    int t[n + 1][w + 1];
    
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= w; j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= w; j++){
            if(j >= wt[i-1]){
                t[i][j] = max(t[i - 1][j - wt[i - 1]] + val[i - 1], t[i - 1][j]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    
    cout<<t[n][w];
}