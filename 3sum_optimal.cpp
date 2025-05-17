class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // applying two pointer method
            int n=nums.size();
            vector<vector<int>> answer;
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++)
            {
                if(i>0 && nums[i]==nums[i-1])
                    continue;
    
                int j=i+1;
                int k=n-1;
                while(j<k)
                {
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum<0)
                        j++;
                    else if(sum>0)
                        k--;
                    else
                    {
                        answer.push_back({nums[i],nums[j],nums[k]});
                        j++;k--;
    
                        while(j<k && nums[j]==nums[j-1])
                           j++;
                    }
                }
            }
            return answer;
        }
    };