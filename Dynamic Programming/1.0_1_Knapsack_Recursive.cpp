#include <iostream>
using namespace std;

int Knapsack(int* wt, int* val,int wt_lft, int n)
{
    if(n == 0 || wt_lft == 0) {
        return 0;
    }
    if(wt_lft >= wt[n - 1]) {
        return max((Knapsack(wt, val, wt_lft - wt[n - 1], n - 1) + val[n - 1]), Knapsack(wt, val, wt_lft, n - 1));
    }

    else
        return Knapsack(wt, val, wt_lft, n - 1);
}

int main()
{

    int wt[] = { 1,3,4,5 };
    int val[] = { 1,4,5,7 };
    int n = 4;
    int w = 10;
    int max = Knapsack(wt, val, w, n);
    cout << max;

    return 0;
}