//TC: O(2^n)

class Solution {
public:
    void solve(int n,vector<string>& ans,string& s){
        int len=s.size();
        if(len==n)
        {
            ans.push_back(s);
            return;
        }
        
        // inserting 0 iff last element inserted is 1 OR
        // the string is empty (first insertion)
        if(s.empty() || s.back()=='1')
        {
            s.push_back('0');
            solve(n,ans,s);
            s.pop_back();
        }
        //inserting 1
        s.push_back('1');
        solve(n,ans,s);
        s.pop_back();
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string s;
        solve(n,ans,s);
        return ans;
    }
};