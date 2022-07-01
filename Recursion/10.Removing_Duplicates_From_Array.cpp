#include <iostream>
#include <string>
using namespace std;

string works(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    else
    {
        char a = s.at(0);
        string k = works(s.substr(1));
        if (k.find(a) != string::npos)
        {
            return k;
        }
        else
            return (a + k);
    }
}

string momo(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    else
    {
        string k = s.substr(s.length() - 1, s.length());
        string k1 = s.substr(0, s.length() - 1);
        if (k1.find(k) != string::npos)
            return momo(k1);

        else
            return momo(k1 + k);
    }
}

int main()
{
    string s = momo("aaaaabbbbcccccccdddddeeeeeeeeefffffffaff");
    cout << s;
}