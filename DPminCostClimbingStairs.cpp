// function ofr normal Recurssivr approach
int solve(vector<int>& cost,int currStair){
        if (currStair>=cost.size())
            return 0;
        return cost[currStair]+min(solve(cost,currStair+1),solve(cost,currStair+2));
    }


// Using DP : Tabular format
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for (int i=2;i<n;i++)
        {
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }

        return min(dp[n-1],dp[n-2]);
    }   
};


//Space optimised code
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prev0=cost[0];
        int prev1=cost[1];
        for (int i=2;i<n;i++)
        {
            int curr=cost[i]+min(prev0,prev1);
            prev0=prev1;
            prev1=curr;
        }

        return min(prev0,prev1);
    }   
};