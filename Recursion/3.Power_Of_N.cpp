#include <iostream>
using namespace std;

int Power_Of_N(int n, int pow)
{
    if (pow == 0)
        return 1;

    return (n * Power_Of_N(n, pow - 1));
}

int main()
{
    int n;
    cin >> n;
    int pow;
    cin >> pow;
    cout << Power_Of_N(n, pow);
}
