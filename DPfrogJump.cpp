// Recurssive Approach

class Solution {
  public:
    int solve(vector<int>& height,int prevStep,int currStep){
        int n=height.size();
        if(currStep==n-1)
            return abs(height[prevStep]-height[currStep]);
        if(currStep>=n)
            return INT_MAX;
        int left=abs(height[prevStep]-height[currStep])+solve(height,currStep,currStep+1);
        int right=abs(height[prevStep]-height[currStep])+solve(height,currStep,currStep+2);
        
        return min(left,right);
    }
    
    int minCost(vector<int>& height) {
        int n=height.size();
        if(n==1)
            return 0;
        int ans1=solve(height,0,1);
        int ans2=solve(height,0,2);
        return min(ans1,ans2);
    }
};

// DP Approach
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int> dp(n,0);
        dp[0]=0;
        // dp[1]=abs(height[1]-0);
        for(int i=1;i<n;i++)
        {
            int one_step=abs(height[i]-height[i-1])+dp[i-1];
            int two_step=INT_MAX;
            if (i>1)
                two_step=abs(height[i]-height[i-2])+dp[i-2];
            dp[i]=min(one_step,two_step);
        }
        
        return dp[n-1];
    }
};

// Space Optimised Approach
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
        int prev1=0;
        int prev2=0;
        // dp[1]=abs(height[1]-0);
        for(int i=1;i<n;i++)
        {
            int oneStep=abs(height[i]-height[i-1])+prev1;
            int twoStep=INT_MAX;
            if(i>1)
                twoStep=abs(height[i]-height[i-2])+prev2;
            int curr=min(oneStep,twoStep);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};