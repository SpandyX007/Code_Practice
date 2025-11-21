// TC: 2^(2*n)
class Solution {
public:
    // take variables n1 and n2, where n1 is the left parenthesis and n2 is the right parenthesis. If n2>n1 return.
    // solve all the valid parenthesis using backtracking

    // return the string including all the possible valid parenthesis
    void solve(vector<string>& ans, string& s, int n, int open, int closed){
        if(s.size()==2*n)
        {
            ans.push_back(s);
            return;
        }
        //validating the braces
        if(open<n)
        {
            s+="(";
            solve(ans,s,n,open+1,closed);
            s.pop_back();
        }
        if(closed<open)
        {
            s+=")";
            solve(ans,s,n,open,closed+1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        solve(ans,s,n,0,0);
        return ans;
    }
};