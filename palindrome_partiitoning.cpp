class Solution {
public:
    bool isPalin(string part){
        int n=part.size();
        int flag=true;
        for(int i=0,j=n-1; i<n && j>=0; i++,j--)
            if(part[i]!=part[j])
                flag=false;
        return flag;
    }
    void helper(string s, vector<string> &ans, vector<vector<string>> &grandans){
        if(s.size()==0) //if the string becomes empty we are stopping the partitioning
        {
            grandans.push_back(ans);
            return;
        }

        for(int i=0;i<s.size();i++)
        {
            string part=s.substr(0,i+1);    //storing the left side of the string
            if(isPalin(part))   //checking if part is palindrome or not
            {
                ans.push_back(part);    
                helper(s.substr(i+1),ans,grandans); //pass the right side of the string to check for more partitions
                ans.pop_back(); //popping the values while backtracking so that we get a empty vector
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> grandans;

        helper(s,ans,grandans);
        return grandans;
    }
};