//using extra space
// TC: O(n); SC: O(n)

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            unordered_set<int> s;
            int n=nums.size();
    
            for(int i=0;i<n;i++)
            {
                if(s.find(nums[i])!=s.end())
                    return nums[i];
                s.insert(nums[i]);
            }
            return -1;
        }
    };


// using fast and slow pointer: no extra space
// TC: O(n); SC: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //using slow and fast pointer

        int slow=nums[0];
        int fast=nums[0];

        //incrementing the pointers
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        //reseting slow
        slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;

    }
};