// Basic Recursive Code
// TC: O(2^(n*m))    SC:O(n) * O(n*n)
class Solution {
public:
    int solve(vector<vector<int>>& grid, int m, int n){
        int row=grid.size();
        int col=grid[0].size();
        
        if(m>row-1 || n>col-1)
            return INT_MAX;
        if(m==row-1 && n==col-1)
            return grid[m][n];
        int down=solve(grid,m+1,n);
        int right=solve(grid,m,n+1);
        return grid[m][n]+min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        return solve(grid,0,0);
    }
};



// Memoization Code
// TC: O(n*m)      SC:O(n) * O(n)
class Solution {
public:
    int solve(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){
        int row=grid.size();
        int col=grid[0].size();
        
        if(m>row-1 || n>col-1)
            return INT_MAX;
        if(m==row-1 && n==col-1)
            return grid[m][n];
        if(dp[m][n]!=-1)
            return dp[m][n];
        int down=solve(grid,m+1,n,dp);
        int right=solve(grid,m,n+1,dp);
        return dp[m][n]=grid[m][n]+min(down,right);
        // return grid[m][n]+min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(grid,0,0,dp);
    }
};



// Tabulation
// TC:O(n*m)    SC:O(n)
