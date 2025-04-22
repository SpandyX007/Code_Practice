#include<iostream>
#include <vector>
using namespace std;

vector<int> nums={1,2,3,4};

vector<int> spandybruteforce(){
    //nice try, but TC=O(n^2)
    vector<int> vec;
    // int *ptr;
    for(int j=0;j<nums.size();j++)
    {
        int ans=1;
        for(int i=0;i<nums.size();i++)
        {
            //ptr=&nums[0];
            if(nums[i]!=nums[j])
            {
                ans=ans*nums[i];
                //vec.push_back(ans);
            }
            else
                continue;
            //ptr++;
        }
        vec.push_back(ans);
    }

    for(int k=0;k<vec.size();k++)
    {
        cout<<vec[k]<<"\t";
    }
}

vector<int> spacecompunoptimised(){
    //TC=O(n) and SC=O(n)
    int n=nums.size();
    vector<int> ans(n);
    vector<int> prefix(n,1);
    vector<int> suffix(n,1);
    //prefix
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]*nums[i-1];
    }
    //suffix
    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=suffix[i+1]*nums[i+1];
    }
    //calculating answer
    for(int i=0;i<n;i++)
    {
        ans[i]=prefix[i]*suffix[i];
    }

    for(int k=0;k<ans.size();k++)
    {
        cout<<ans[k]<<"\t";
    }
}

vector<int> spacecompoptimised(){
    //TC=O(n) and SC=O(1)
    int n=nums.size();
    vector<int> ans(n,1);
    for(int i=1;i<n;i++)
    {
        ans[i]=ans[i-1]*nums[i-1];
    }
    int suffix=1;
    for(int i=n-2;i>=0;i--)
    {
        suffix*=nums[i+1];
        ans[i]*=suffix;
    }

    for(int k=0;k<ans.size();k++)
    {
        cout<<ans[k]<<"\t";
    }
}

int main(){

    spandybruteforce();
    cout<<endl;
    spacecompunoptimised();
    cout<<endl;
    spacecompoptimised();

    return 0;
}