//Brute force Approach
// TC:O(2^n)      SC:O(n) * O(n*4)

class Solution {
  public:
    int solve(vector<vector<int>>& arr, int dayIdx, int prevSkill){
        int n=arr.size();
        if(dayIdx==n-1)
        {
            int maxSkill=INT_MIN;
            for(int i=0;i<3;i++)
            {
                if(i!=prevSkill)
                    maxSkill=max(maxSkill,arr[dayIdx][i]);
            }
            return maxSkill;
        }
        int maxSkill=INT_MIN;
        for(int i=0;i<3;i++)
        {
            if(i!=prevSkill)
            {
                int points=arr[dayIdx][i]+solve(arr,dayIdx+1,i);
                maxSkill=max(points,maxSkill);
            }
        }
        return maxSkill;
           
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
        return solve(arr,0,3);
    }
};


// Memoization Code
// TC:O(n*4)*3      SC:O(n) * O(n*4)
class Solution {
  public:
    int solve(vector<vector<int>>& arr,vector<vector<int>>& dp, int dayIdx, int prevSkill){
        int n=arr.size();
        if(dayIdx==n-1)
        {
            int maxSkill=INT_MIN;
            for(int i=0;i<3;i++)
            {
                if(i!=prevSkill)
                    maxSkill=max(maxSkill,arr[dayIdx][i]);
            }
            return maxSkill;
        }
        
        if(dp[dayIdx][prevSkill]!=-1)
            return dp[dayIdx][prevSkill];
        
        int maxSkill=INT_MIN;
        for(int i=0;i<3;i++)
        {
            if(i!=prevSkill)
            {
                int points=arr[dayIdx][i]+solve(arr,dp,dayIdx+1,i);
                maxSkill=max(points,maxSkill);
            }
        }
        return dp[dayIdx][prevSkill]=maxSkill;
           
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(arr,dp,0,3);
    }
};

// Tabulation Code
// TC:O(n*4)*3      SC:O(n*4)
class Solution {
  public:    
    int maximumPoints(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(4,0));
        
        // filling the initial matrix
        dp[0][0]=max(arr[0][1],arr[0][2]);
        dp[0][1]=max(arr[0][0],arr[0][2]);
        dp[0][2]=max(arr[0][0],arr[0][1]);
        dp[0][3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
        
        for(int day=1;day<n;day++)
        {
            for(int prevSkill=0;prevSkill<4;prevSkill++)
            {
                dp[day][prevSkill]=0;
                for(int currSkill=0;currSkill<3;currSkill++)
                {
                    if(currSkill!=prevSkill)
                    {
                        int point=arr[day][currSkill]+dp[day-1][currSkill];
                        dp[day][prevSkill]=max(point,dp[day][prevSkill]);
                    }
                }
            }
        }
        
        return dp[n-1][3];
    }
};



// Space Optimisation Code
// TC: O(n*4)*3     SC:O(4)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int> prev(4,0);
        
        // filling the initial matrix
        prev[0]=max(arr[0][1],arr[0][2]);
        prev[1]=max(arr[0][0],arr[0][2]);
        prev[2]=max(arr[0][0],arr[0][1]);
        prev[3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
        
        for(int day=1;day<n;day++)
        {
            vector<int> temp(4,0);
            for(int prevSkill=0;prevSkill<4;prevSkill++)
            {
                temp[prevSkill]=0;
                for(int currSkill=0;currSkill<3;currSkill++)
                {
                    if(currSkill!=prevSkill)
                    {
                        int point=arr[day][currSkill]+prev[currSkill];
                        temp[prevSkill]=max(point,temp[prevSkill]);
                    }
                }
            }
            prev=temp;
        }
        
        return prev[3];
    }
};