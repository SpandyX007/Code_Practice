// time Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using hashing 
        unordered_map<int,int> m;
        vector<int> answer;

        for(int i=0;i<nums.size();i++)
        {
            int first = nums[i];
            int second = target - first;

            if(m.find(second)!=m.end()) // element is found
            {
                answer.push_back(first);
                answer.push_back(second);
                break;
            }

            m[first] = i;
        }

        return answer;
    }
};

// time Complexity: O(nlogn)
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            //using sorting and two pointer method
            vector<int> answer;
            vector<pair<int,int>> numswithidx;
    
            //storing the orginal index 
            for(int i=0;i<nums.size();i++)
            {
                numswithidx.push_back({nums[i],i});
            }
            
            sort(numswithidx.begin(),numswithidx.end());      //takes O(nlogn) time
    
            // applying two pointer
            int start=0;
            int end=nums.size()-1;
    
            while(start<end)
            {
                if(numswithidx[start].first+numswithidx[end].first==target)
                {
                    answer.push_back(numswithidx[start].second);
                    answer.push_back(numswithidx[end].second);
                    break;
                }
                else if(numswithidx[start].first+numswithidx[end].first>target)
                    end--;
                else
                    start++;
            }
            return answer;
        }
    };