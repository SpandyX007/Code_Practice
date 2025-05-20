class Solution {
    public:
        vector<vector<int>> grandans;
        void subsets(vector<int> &arr,vector<int> &ans, int i){
            if(i==arr.size())
            {
                grandans.push_back(ans);
                return;
            }
    
            //include
            ans.push_back(arr[i]);
            subsets(arr,ans,i+1);
    
            //exclude
            ans.pop_back();
            subsets(arr,ans,i+1);
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> ans;
            subsets(nums,ans,0);
    
            return grandans;
        }
    };