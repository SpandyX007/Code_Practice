// Brute force Recursive solution
// TC: O(2^n)   SC: O(n) * O(n)
class Solution {
public:
    int solve(int m, int n,int currm, int currn){
        if(currm==m-1 && currn==n-1)
            return 1;
        if(currm>=m || currm<0 || currn<0 || currn>=n)
            return 0;
        int down=solve(m,n,currm+1,currn);
        int right=solve(m,n,currm,currn+1);
        return down+right;
    }

    int uniquePaths(int m, int n) {
        return solve(m,n,0,0);
    }
};


// Memoization Approach
// TC:O(n*m)    SC:O(n-1 * m-1)
class Solution {
public:
    int solve(int m, int n,int currm, int currn, vector<vector<int>>& dp){
        if(currm==m-1 && currn==n-1)
            return 1;
        if(currm>=m || currm<0 || currn<0 || currn>=n)
            return 0;
        if(dp[currm][currn]!=-1)
            return dp[currm][currn];

        int down=solve(m,n,currm+1,currn,dp);
        int right=solve(m,n,currm,currn+1,dp);
        return dp[currm][currn]=down+right;
    }

    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m,n,0,0,dp);
    }
};



// Tabulation Problem
// TC: O(n*m)       SC:O(n*m)
class Solution {
public:
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    continue;
                else
                {
                    int up=0,left=0;
                    if(i>0)
                        up=dp[i-1][j];
                    if(j>0)
                        left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }

        return dp[m-1][n-1];
    }
};

// Space Optimation Approach
// TC: O(n*m)       SC:O(n)
class Solution {
public:
    int uniquePaths(int m, int n){
        vector<int> prev(n,0);
        // prev[0]=1;
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    curr[j]=1;
                else
                {
                    int up=0,left=0;
                    if(i>0)
                        up=prev[j];
                    if(j>0)
                        left=curr[j-1];
                    curr[j]=up+left;
                }
            }
            prev=curr;
        }

        return prev[n-1];
    }
};