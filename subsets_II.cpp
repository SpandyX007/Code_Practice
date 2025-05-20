class Solution {
    public:
        vector<vector<int>> grandans;
        void subsets(vector<int> &arr, vector<int> &ans, int i){
            if(i==arr.size())
            {
                grandans.push_back(ans);
                return;
            }
    
            //inclusion
            ans.push_back(arr[i]);
            subsets(arr,ans,i+1);
    
            //exclusion for repeated elements
            ans.pop_back();
            int idx=i+1;
            while(idx<arr.size() && arr[idx]==arr[idx-1])
                idx++;
            subsets(arr,ans,idx);
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<int> ans;
            subsets(nums,ans,0);
            return grandans;
        }
    };