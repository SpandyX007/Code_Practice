//working fine...no issues...leetcode is fuked up

#include<iostream>
using namespace std;

int top=-1;
char stack[100000];

void push(char item){
    top++;
    stack[top]=item;
}

void pop(){
    stack[top]=0;
    top--;
}

bool isValid(string s){
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                push(s[i]);
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(s[i]==')' && stack[top]=='(')
                    pop();
                else if(s[i]=='}' && stack[top]=='{')
                    pop();
                else if(s[i]==']' && stack[top]=='[')
                    pop();
                else
                    return false;
            }
            else
                continue;
        }
        if(top==-1)
            return true;
}

int main(){

    int top=-1;
    char stack[100000];

    string s="{({}[])}";
    bool result=isValid(s);
    cout<<result<<endl;

    return 0;
}