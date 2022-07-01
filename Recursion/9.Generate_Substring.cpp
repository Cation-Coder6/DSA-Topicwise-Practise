#include <iostream>
#include <string>
using namespace std;

void subseq(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << " ";
    }
    else
    {
        char ch = input[0];
        int x = ch;
        subseq(input.substr(1), output + ch);
        subseq(input.substr(1), output);
        subseq(input.substr(1), output + (to_string(x)));
    }
}

int main()
{
    subseq("AB", "");
}