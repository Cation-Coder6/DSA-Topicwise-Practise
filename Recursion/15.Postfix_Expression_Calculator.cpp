#include<iostream>
#include<stack>
#include<string>
using namespace std;

int prefix_Calculator(string st){
    int op1 , op2;
    stack<int> s;
    for(int i=0;i<st.length();i++){
        if(st.at(i)>='0' && st.at(i)<='9'){
            s.push(st[i]-'0');
        }
        if(st.at(i) == '+'){
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            s.push(op1 + op2);
        }
        if(st.at(i) == '-'){
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            s.push(op1 - op2);        
        }
        if(st.at(i) == '*'){
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            s.push(op1 * op2);        
        }
        if(st.at(i) == '/'){
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            s.push(op1 / op2);        
        }
    }
    return s.top();
}





int main(){
    cout<<prefix_Calculator("46+2/5*7+");
    
}