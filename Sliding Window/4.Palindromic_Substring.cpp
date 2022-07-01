#include<iostream>
#include<string>
#include<cmath>
using namespace std;


bool ispalindrome(int num){
    int temp = 0;
    int ans = num;
    while(num>0){
        temp= temp10 + num%10;
        num = num/10;
    }
    if(temp == ans){
        cout<<"\nThe palindromic number is :-"<<ans<<endl;
        return 1;
    }

        else return 0;
}


int main(){
    int n;
    cout<<"\nEnter the size of the array :- ";

    cin>>n;

    int a[n];
    cout<<"\nEnter the elements of the array :- ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int k;
    cout<<"\nEnter the size of the subarray :- ";
    cin>>k;

    int num = 0;
    for(int i=0;i<k;i++){
        num = num10 + a[i];
    }
    if(ispalindrome(num)){
        cout<<"\nPalindrome found\n";
        return 0;
    }
    for(int i=k;i<n;i++){
        num = ((num % (int)(pow(10 , k-1))) *10) + a[i];
        if(ispalindrome(num)){
            cout<<"\nPalindrome found\n";
            return 0;
        }
    }
    cout<<"\nPalindrome Not Found\n";
    return 0;

}