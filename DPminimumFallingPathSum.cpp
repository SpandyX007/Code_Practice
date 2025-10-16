// Brute-force: Recursion
// TC: O(3^n)
class Solution {
public:
    int solve(vector<vector<int>>& matrix, int crow, int ccol){
        int n=matrix.size();
        if(ccol<0 || ccol>=n)
            return INT_MAX;
        if(crow==n-1)
            return matrix[crow][ccol];
        int down=solve(matrix,crow+1,ccol);
        int left=solve(matrix,crow+1,ccol-1);
        int right=solve(matrix,crow+1,ccol+1);
        return matrix[crow][ccol]+min(down,min(left,right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
            ans=min(ans,solve(matrix,0,i));
        return ans;
    }
};


// Memoization
// TC:O(n^2)
class Solution {
public:
    int solve(vector<vector<int>>& matrix, int crow, int ccol,vector<vector<int>>& dp){
        int n=matrix.size();
        if(ccol<0 || ccol>=n)
            return INT_MAX;
        if(crow==n-1)
            return matrix[crow][ccol];
        if(dp[crow][ccol]!=-1)
            return dp[crow][ccol];
        int down=solve(matrix,crow+1,ccol,dp);
        int left=solve(matrix,crow+1,ccol-1,dp);
        int right=solve(matrix,crow+1,ccol+1,dp);
        return dp[crow][ccol]=matrix[crow][ccol]+min(down,min(left,right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
            ans=min(ans,solve(matrix,0,i,dp));
        return ans;
    }
};

// Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++)
            dp[0][j]=matrix[0][j];
        for(int i=1;i<n;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                int up=dp[i-1][j];
                int left=(j-1>=0)?dp[i-1][j-1]:INT_MAX;
                int right=(j+1<n)?dp[i-1][j+1]:INT_MAX;
                dp[i][j]=matrix[i][j]+min(up,min(left,right));
            }
        }

        int ans=INT_MAX;
        for(int j=0;j<n;j++)
            ans=min(ans,dp[n-1][j]);
        return ans;
    }
};

// Space Optimisation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev(n,0),curr(n,0);
        for(int j=0;j<n;j++)
            prev[j]=matrix[0][j];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up=prev[j];
                int left=(j-1>=0)?prev[j-1]:INT_MAX;
                int right=(j+1<n)?prev[j+1]:INT_MAX;
                curr[j]=matrix[i][j]+min(up,min(left,right));
            }
            prev=curr;
        }

        int ans=INT_MAX;
        for(int j=0;j<n;j++)
            ans=min(ans,prev[j]);
        return ans;
    }
};