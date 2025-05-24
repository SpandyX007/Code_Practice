class Solution {
public:
    set<vector<int>> s;
    void findcombinations(vector<int>& arr, int target, int idx, vector<vector<int>> &grandanswer, vector<int> &answer){
        int n=arr.size();
        if(target==0)
        {
            if(s.find(answer)==s.end())
            {
                grandanswer.push_back(answer);
                s.insert(answer);
            }
            return;
        }
        if(idx==n || target<0)
            return;
        
        //include the value
        answer.push_back(arr[idx]);
        findcombinations(arr,target-arr[idx],idx+1,grandanswer,answer);

        //include the repeating values
        findcombinations(arr,target-arr[idx],idx,grandanswer,answer);

        //exclude the value
        answer.pop_back();
        findcombinations(arr,target,idx+1,grandanswer,answer);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> grandanswer;
        vector<int> answer;
        findcombinations(arr,target,0,grandanswer,answer);
        return grandanswer;
    }
};