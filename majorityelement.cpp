#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int bruteforce(vector<int>& nums){
    int count=0, n=nums.size();
    for (int i: nums)
    {
        for(int j: nums)
        {
            if(i==j)
            {
                count++;
                cout<<count;
            }
        }
        if(count>(n/2))
            return i;
    }
}

int optimisedbruteforce(vector<int>& nums){
    //sorting the array first
    int freq=1, ans=nums[0], n=nums.size();
    sort(nums.begin(), nums.end());
    for (int i=0;i<n; i++)
    {
        if(nums[i]==nums[i-1])
            freq++;
        else
        {
            freq=1;
            ans=nums[i];
        }
    }

    if(freq>(n/2))
        return ans;

    return ans;
}

int main(){

    int n=3;
    vector<int> vec={6,5,5};
    //int majorityele=bruteforce(vec);
    int majorityele=optimisedbruteforce(vec);
    cout<<"The majority element is= "<<majorityele;

    return 0;
}