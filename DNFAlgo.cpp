// sort the array {0,2,1,2,1,0} like {0,0,1,1,2,2}
//logic written in notebook

#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> nums={0,2,1,2,1,0};
    int n=nums.size();
    int low=0,mid=0,high=n-1;

    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid],nums[high]);
            high--;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<"\t";
    }

    return 0;
}