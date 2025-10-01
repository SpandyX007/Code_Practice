// TC: O(2^n)
// Brute-force recursive solution
class Solution {
public:
    int solve(vector<int>& nums, int i){
        int n=nums.size();
        if(i==n-1)
            return nums[i];
        if(i>=n)
            return 0;
        int pick=nums[i]+solve(nums,i+2);
        int notpick=solve(nums,i+1);
        return max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        int ans=solve(nums,0);
        return ans;
    }
};


// Using DP (tabulation)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];

        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int pick=nums[i]+dp[i-2];
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};

// Space Optimised
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];

        // vector<int> dp(n,0);
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int pick=nums[i]+prev2;
            int notpick=prev1;
            int curr=max(pick,notpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};