class Solution {
public:
    int solve(vector<vector<int>>& triangle,int crow, int ccol, vector<vector<int>>& dp){
        int n=triangle.size();
        if(crow==n-1)
            return triangle[n-1][ccol];
        int left=triangle[crow][ccol]+solve(triangle, crow+1,ccol,dp);
        int right=triangle[crow][ccol]+solve(triangle,crow+1,ccol+1,dp);
        return min(left,right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle, 0, 0,dp);
    }
};

// Memoization Code
// TC: O(n*m)       SC: O(n) * O(n*m)
class Solution {
public:
    int solve(vector<vector<int>>& triangle,int crow, int ccol, vector<vector<int>>& dp){
        int n=triangle.size();
        if(crow==n-1)
            return triangle[n-1][ccol];
        if(dp[crow][ccol]!=-1)
            return dp[crow][ccol];
        int left=triangle[crow][ccol]+solve(triangle, crow+1,ccol,dp);
        int right=triangle[crow][ccol]+solve(triangle,crow+1,ccol+1,dp);
        return dp[crow][ccol]=min(left,right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(triangle, 0, 0,dp);
    }
};

// Tabulation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int j=0;j<n;j++)
            dp[n-1][j]=triangle[n-1][j];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int left=triangle[i][j]+dp[i+1][j];
                int right=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(left,right);
            }
        }
        return dp[0][0];
    }
};


// Space Optimisation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<int> dp(m,-1);
        vector<int> curr(m,0);

        for(int i=0;i<n;i++)
            dp[i]=triangle[n-1][i];

        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int left=triangle[i][j]+dp[j];
                int right=triangle[i][j]+dp[j+1];
                curr[j]=min(left,right);
            }
            dp=curr;
        }
        return dp[0];
    }
};