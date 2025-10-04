//Brute Force Recursive approach
// TC: O(2^(m+n))       SC:O(n) * O(m*n)

class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int row,int col){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // Out of bounds OR obstacle
        if (row >= m || col >= n || obstacleGrid[row][col] == 1) 
            return 0;
        // Reached destination safely
        if (row == m - 1 && col == n - 1) 
            return 1;
        int down=solve(obstacleGrid,row+1,col);
        int right=solve(obstacleGrid,row,col+1);
        return down+right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return solve(obstacleGrid,0,0);
    }
};



// Memoization Approach
// TC: O(n*n)       SC:O(n) * O(n*n)
class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int row,int col,vector<vector<int>>& dp){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // Out of bounds OR obstacle
        if (row >= m || col >= n || obstacleGrid[row][col] == 1) 
            return 0;
        // Reached destination safely
        if (row == m - 1 && col == n - 1) 
            return 1;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int down=solve(obstacleGrid,row+1,col,dp);
        int right=solve(obstacleGrid,row,col+1,dp);
        return dp[row][col]=down+right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(obstacleGrid,0,0,dp);
    }
};



// Tabulation Method
// TC: O(n*n)       SC:O(n*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;

        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if (obstacleGrid[row][col] == 1) {
                    curr[col] = 0; // obstacle cell
                    continue;
                }
                if (row==0 && col==0 && obstacleGrid[row][col]!=1)
                    continue;
                int up=0,left=0;
                if(row>0)
                    up=dp[row-1][col];
                if(col>0)
                    left=dp[row][col-1];
                dp[row][col]=up+left;
            }
        }

        return dp[m-1][n-1];
    }
};



// Space Optimisation
// TC:O(n*n)        SC:O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> prev(n,0);

        for(int row=0;row<m;row++)
        {
            vector<int> curr(n,0);
            for(int col=0;col<n;col++)
            {
                if (obstacleGrid[row][col] == 1) {
                    curr[col] = 0; // obstacle cell
                    continue;
                }
                if (row==0 && col==0 && obstacleGrid[row][col]!=1)
                    curr[col]=1;
                else
                {
                    int up=0,left=0;
                    if(row>0)
                        up=prev[col];
                    if(col>0)
                        left=curr[col-1];
                    curr[col]=up+left;
                }
            }
            prev=curr;
        }

        return prev[n-1];
    }
};