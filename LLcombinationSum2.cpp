// my solution

class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, int sum, vector<int>& sumarr, set<vector<int>>& ans){
        int n=candidates.size();
        if(sum==target)
        {
            ans.insert(sumarr);
            return;
        }

        if(i==n || sum>target)
            return;
        
        //inclusion
        sumarr.push_back(candidates[i]);
        solve(candidates,target,i+1,sum+candidates[i],sumarr,ans);
        sumarr.pop_back();
        //exclusion
        solve(candidates,target,i+1,sum,sumarr,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> sumarr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,0,sumarr,ans);

        vector<vector<int>> sub;
        for(auto ele:ans)
            sub.push_back(ele);
        return sub;
    }
};



//optimised
// TC: O(2^n)
class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& sumarr, int idx, int sum, vector<vector<int>>& ans){
        // int n=candidates.size();
        if(sum==target)
        {
            ans.push_back(sumarr);
            return;
        }
        
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
                continue;
            if(sum+candidates[i]>target)
                break;
            sumarr.push_back(candidates[i]);
            solve(candidates,target,sumarr,i+1,sum+candidates[i],ans);
            sumarr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sumarr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,sumarr,0,0,ans);
        return ans;
    }
};