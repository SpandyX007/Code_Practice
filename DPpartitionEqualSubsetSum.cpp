// recurssive approach
// TC: O(2^n)   SC:O(n)

class Solution {
public:
    bool targetSum(vector<int>& nums, int i, int target, int sum){
        int n=nums.size();
        if(sum==target)
            return true;
        if(sum>target || i==n)
            return false;

        //include 
        bool include=targetSum(nums,i+1,target,sum+nums[i]);
        //exclude
        bool exclude=targetSum(nums,i+1,target,sum);
        return include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        // calculating sum of nums
        int arrsum=0;
        for(int ele:nums)
            arrsum+=ele;

        return (arrsum%2!=0) ? false : targetSum(nums,0,arrsum/2,0);
    }
};

// using memoisation approach
// TC:O(n*target)  SC:O(n*target) + o(n)
class Solution {
  public:
    bool solve(vector<int>& arr, int i, int target, int sum, vector<vector<int>>& dp){
        int n=arr.size();
        if(sum==target)
            return true;
        if(i==n || sum>target)
            return false;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        bool taken=solve(arr,i+1,target,sum+arr[i],dp);
        bool nottaken=solve(arr,i+1,target,sum,dp);
        return dp[i][sum]=taken || nottaken;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(arr,0,sum,0,dp);
    }
};

// tabulation method
// TC:O(n*target) SC:O(n*target)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        // dp[n][target]
        
        // writng the reversed base cases
        for(int i=0;i<n;i++)
            dp[i][0]=true;
        if(arr[0]<=target)
            dp[0][arr[0]]=true;
        
        // writing the nested loops with the recerance
        for(int i=1;i<n;i++)
        {
            for(int sum=1;sum<=target;sum++)
            {
                bool nottaken=dp[i-1][sum];
                bool taken=false;   //just initialised taken variable
                if(arr[i]<=sum)
                    taken=dp[i-1][sum-arr[i]];
                dp[i][sum]=taken || nottaken;
            }
        }
        
        // final answer
        return dp[n-1][target];
    }
};

//Space optimisation
// TC: O(n*target)     SC:O(n)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> prev(target+1,0),curr(target+1,0);
        
        // writng the reversed base cases
        prev[0]=curr[0]=true;
        if (arr[0] <= target)
            prev[arr[0]]=true;
        
        // writing the nested loops with the recerance
        for(int i=1;i<n;i++)
        {
            for(int sum=1;sum<=target;sum++)
            {
                bool nottaken=prev[sum];
                bool taken=false;   //just initialised taken variable
                if(arr[i]<=sum)
                    taken=prev[sum-arr[i]];
                curr[sum]=taken || nottaken;
            }
            prev=curr;
        }
        
        // final answer
        return prev[target];
    }
};