// brute-force
// TC:O(2^n)
class Solution {
  public:
    void solve(int n,vector<string>& ans,string& s){
        int len=s.size();
        if(len==n)
        {
            ans.push_back(s);
            return;
        }
        if(len>n)
            return;
        // inserting 0
        s.push_back('0');
        solve(n,ans,s);
        s.pop_back();
        //inserting 1
        s.push_back('1');
        solve(n,ans,s);
        s.pop_back();
    }
    
    vector<string> binstr(int n) {
        vector<string> ans;
        string s;
        solve(n,ans,s);
        return ans;
    }
};