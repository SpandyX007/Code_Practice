// Using normal recurrsion approach (TLE)
// TC: O(2^n)
class Solution {
public:
    int climbStairs(int n) {
        // we have to use the DP for to reach 0 to n
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        int left=climbStairs(n-1);
        int right=climbStairs(n-2);
        return left+right;
    }
};

// Using DP Approach
// TC: O(n);    SC:O(n)
class Solution {
public:
    int climbStairs(int n) {
        // we have to use the DP for to reach 0 to n
        if(n<=1)
            return 1;
        vector<int> dp_table(n+1,0);
        dp_table[0]=1;
        dp_table[1]=1;
        for(int i=2;i<=n;i++)
            dp_table[i]=dp_table[i-1]+dp_table[i-2];
        return dp_table[n];
    }
};

// Using Space Optimization Approach
// TC:O(N)      SC:O(1)
class Solution {
public:
    int climbStairs(int n) {
        // we have to use the DP for to reach 0 to n
        if(n<=1)
            return 1;
        int t1=1;
        int t2=1;
        for(int i=2;i<=n;i++)
        {
            int t3=t1+t2;
            t1=t2;
            t2=t3;
        }
        return t2;
    }
};