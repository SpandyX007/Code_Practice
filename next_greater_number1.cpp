// brute force approach     TC:O(n^2)       SC:O(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),0);
        stack<int> s;
        for (int i=nums1.size()-1; i>=0;i--)
        {
            for(int j=nums2.size()-1;j>=0;j--)
            {
                if(nums1[i]==nums2[j])
                {
                    while(s.size()>0 && s.top()<=nums2[j])
                        s.pop();
                    if(s.empty())
                        ans[i]=-1;
                    else
                        ans[i]=s.top();
                }
                else
                    s.push(nums2[j]);
            }
        }
        return ans;
    }
};


// Optimised using Hashmap
class Solution {
public:
    unordered_map<int,int> m;
    stack<int> s;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        //finding next greater for nums2 adn storing in hashmap
        for (int i=nums2.size()-1;i>=0;i--)
        {
            while(s.size()>0 && s.top()<nums2[i])
                s.pop();
            if(s.empty())
                m[nums2[i]]=-1;
            else
                m[nums2[i]]=s.top();
            s.push(nums2[i]);
        }

        //traversing nums1 and searching in hashmap to find the corresponding value
        for(int i=0;i<nums1.size();i++)
            ans.push_back(m[nums1[i]]);
        return ans;
    }
};