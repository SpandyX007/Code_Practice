class Solution {
public:
    int solve(vector<int>& nums,int i){
        int n=nums.size();
        if(i>=n)
            return 0;
        if(i==n-1)
            return nums[i];

        int pick=nums[i]+solve(nums,i+2);
        int notpick=solve(nums,i+1);
        return max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        // The first and the last house can't come together
        //temp1: all elements excluding first element
        //temp2: all elements excluding last element
        int n=nums.size();
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)    temp1.push_back(nums[i]);
            if(i!=n-1)  temp2.push_back(nums[i]);
        }
        return max(solve(temp1,0),solve(temp2,0));
    }
};



// Space optimised approach
class Solution {
public:
    int solve(vector<int>& nums,int i){
        int n=nums.size();
        if(n==0)    return 0;
        if(n==1)    return nums[0];
        
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int pick=nums[i]+prev2;
            int notpick=prev1;
            int curr=max(pick,notpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        // The first and the last house can't come together
        // temp1: all elements excluding first element
        // temp2: all elements excluding last element
        int n=nums.size();
        if(n==0)    return 0;
        if(n==1)    return nums[0];

        vector<int> temp1,temp2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)    temp1.push_back(nums[i]);
            if(i!=n-1)  temp2.push_back(nums[i]);
        }
        return max(solve(temp1,0),solve(temp2,0));
    }
};