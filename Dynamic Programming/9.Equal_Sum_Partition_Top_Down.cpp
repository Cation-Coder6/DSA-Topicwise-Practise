#include <iostream>
using namespace std;

int main()
{
    int ar[] = { 1, 5, 11, 5 };
    int n = 4;

    int k = 0;
    for(int i = 0; i < n; i++) {
        k += ar[i];
    }
    if(k % 2 != 0)
        cout << false;
    else {
        int sum = k / 2;
        bool t[n + 1][sum + 1];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(i == 0 && j != 0) {
                    t[i][j] = 0;
                } else if(j == 0)
                    t[i][j] = 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(j >= ar[i - 1]) {
                    t[i][j] = (t[i - 1][j - ar[i - 1]] || t[i - 1][j]);
                } else
                    t[i][j] = t[i - 1][j];
            }
        }
        cout << t[n][sum];
    }
}