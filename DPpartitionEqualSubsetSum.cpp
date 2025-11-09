class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> prev(target+1,0),curr(target+1,0);
        
        // writng the reversed base cases
        prev[0]=curr[0]=true;
        if (arr[0] <= target)
            prev[arr[0]]=true;
        
        // writing the nested loops with the recerance
        for(int i=1;i<n;i++)
        {
            for(int sum=1;sum<=target;sum++)
            {
                bool nottaken=prev[sum];
                bool taken=false;   //just initialised taken variable
                if(arr[i]<=sum)
                    taken=prev[sum-arr[i]];
                curr[sum]=taken || nottaken;
            }
            prev=curr;
        }
        
        // final answer
        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        // calculating sum of nums
        int arrsum=0;
        for(int ele:nums)
            arrsum+=ele;

        return (arrsum%2!=0) ? false : isSubsetSum(nums,arrsum/2);
    }
};