#include <iostream>
using namespace std;

int Sum_Of_N_Numbers(int n)
{
    if (n == 0)
        return 0;

    return (n + Sum_Of_N_Numbers(n - 1));
}

int main()
{
    int n;
    cin >> n;
    cout << Sum_Of_N_Numbers(n);
}
