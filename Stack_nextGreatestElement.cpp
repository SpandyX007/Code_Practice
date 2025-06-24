// Brute force algorithm        TC: O(n^2) SC:O(1);

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 1};
    vector<int> ans;
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        int found = -1;
        for(int j = 1; j < n; j++) {
            int index = (i + j) % n;
            if(nums[index] > nums[i]) {
                found = nums[index];
                break;
            }
        }
        ans.push_back(found);
    }

    for(int ele: ans)
        cout << ele << "\t";
    cout << endl;

    return 0;
}


// Optimised        TC:O(n)  SC: O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        stack<int> s;

        for(int i=2*n-1; i>=0; i--)
        {
            while(s.size()>0 && nums[s.top()]<=nums[i%n])
                s.pop();
            if(s.empty())
                ans[i%n]=-1;
            else
                ans[i%n]=nums[s.top()];
            s.push(i%n);    //valid index= i%n
        }

        return ans;
    }
};