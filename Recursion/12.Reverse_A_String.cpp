#include <iostream>
#include <string>
using namespace std;

string rev(string s);

void rev(char *s, int beg, int end)
{
    if (beg > end)
    {
        return;
    }

    swap(s[beg], s[end - 1]);
    rev(s, beg + 1, end - 1);
}

int main()
{
    char a[100];
    for (int i = 0; i < 11; i++)
    {
        cin >> a[i];
    }

    rev(a, 0, 11);

    for (int i = 0; i < 11; i++)
    {
        cout << a[i];
    }
}