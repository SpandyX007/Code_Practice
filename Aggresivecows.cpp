#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr={1,2,8,4,9};
int n=arr.size();

bool ispossible(int N,int C,int minallowed){
    int cow=1, laststallpos=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]-laststallpos>=minallowed)
        {
            cow++;
            laststallpos=arr[i];
        }
        if(cow==C)
            return true;
    }
    return false;
}

int getdistance(int N, int C){
    sort(arr.begin(),arr.end());
    int start=1, end=arr[n-1], ans;

    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(ispossible(N,C,mid))
        {
            ans=mid;
            start=mid+1;
        }
        else
            end=mid-1;
    }

    return ans;
}

int main(){

    int N=5, C=3;
    int result=getdistance(N,C);
    cout<<result;

    return 0;
}