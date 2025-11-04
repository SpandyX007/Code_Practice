// my solution
// TC: O(2^n)       SC:O(n^2)
class Solution {
public:
    void targetSum(vector<int>& nums, int i, vector<int>& ans, int target, int sum, vector<vector<int>>& grandans){
    int n=nums.size();
    if(i==n)
    {
        if(sum==target)
            grandans.push_back(ans);
        return;
    }
    
    //positive
    ans.push_back(nums[i]);
    targetSum(nums,i+1,ans,target,sum+nums[i],grandans);
    ans.pop_back();
    //backtrack
    //negative
    ans.push_back(-nums[i]);
    targetSum(nums,i+1,ans,target,sum-nums[i],grandans);
    ans.pop_back();
}
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> ans;
        vector<vector<int>> grandans;
        targetSum(nums,0,ans,target,0,grandans);
        return grandans.size();
    }
};