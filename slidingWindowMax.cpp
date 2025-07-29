class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        queue<int> q;

        vector<int> ans;
        // iteration for 1st window
        for(int i=0; i<k;i++)
        {
            while(dq.size()>0 && nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(i);
        }

        // next windows
        for(int i=k; i<nums.size();i++)
        {
            ans.push_back(nums[dq.front()]);

            //remove not part of current window
            while(dq.size()>0 && dq.front()<=i-k)
                dq.pop_front();

            // reomove the smaller values
            while(dq.size()>0 && nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(i);
        }

        // entering the elements of the last window
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};