#include <iostream>
using namespace std;

bool Subset(int arr[], int sum, int n)
{
    if(n == 0 && sum == 0) {
        return 1;
    } 
    else if(n == 0 && sum != 0) {
        return 0;
    }

    else if(sum >= arr[n - 1]) {
        return ((Subset(arr, sum - arr[n - 1], n - 1)) || (Subset(arr, sum, n - 1)));
    } 
    else
        return Subset(arr, sum, n - 1);
}
int main()
{
    int a[] = { 2, 3, 7, 8, 10 };
    int sum = 16;
    int n = 5;
    cout << Subset(a, sum, n);
}