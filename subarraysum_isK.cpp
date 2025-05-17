// Brute force Approach
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int answer=0;
            int n=nums.size();
            for(int i=0;i<n;i++)
            {
                int sum=0;
                for(int j=i;j<n;j++)
                {
                    sum+=nums[j];
                    if(sum==k)
                        answer++;
                }
            }
            return answer;
        }
    };


//optimised approach
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            //using prefix sum
            int answer=0;
            int n=nums.size();
            unordered_map<int,int> m;   //storing number and its frequency
            vector<int> PreSum;
            int sum=0;
    
            for(int i=0;i<n;i++)
            {
                sum+=nums[i];
                PreSum.push_back(sum);
            }
            for(int j=0;j<n;j++)
            {
                if(PreSum[j]==k)
                    answer++;
    
                int val=PreSum[j]-k;
                if(m.find(val)!=m.end())
                    answer+=m[val];
                    
                if(m.find(PreSum[j])==m.end())
                    m[PreSum[j]]=0;
                m[PreSum[j]]++;
            }
            return answer;
        }
    };