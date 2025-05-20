// pending: implent the logic for LL

#include <bits/stdc++.h>
using namespace std;

void removenum(stack<int> &s, int curr_ele){
    if(s.empty())
    {
        s.push(curr_ele);
        return;
    }
    if(curr_ele>s.top())
    {
        while(!s.empty() && curr_ele>s.top())
        {
            s.pop(); 
        }
    }
    s.push(curr_ele);
}

void displaystack(stack<int> &s){
    while(!s.empty())
    {
        int popped=s.top();
        cout<<popped<<endl;
        s.pop();
    }
    cout<<endl;
}

int main() {
    vector<int> head = {5,2,13,3,8};
    stack<int> s;
    int n=head.size();
       
    
    for(int i=0;i<n;i++)
        removenum(s, head[i]);
    displaystack(s);
    

    return 0;
}