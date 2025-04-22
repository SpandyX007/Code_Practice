#include <iostream>
#include <vector>
using namespace std;

vector<int> vec={40,30,20,10};

bool isPossible(int n,int  m, int maxallowed){
    int painter=1,time=0;
    for(int i=0;i<n;i++)
    {
        if(time+vec[i] <= maxallowed)
            time+=vec[i];
        else
        {
            painter++;
            time=vec[i];
        }
    }
    return painter<=m;
}

int mintimetopaint(int n, int m){
    int start=0,end=0, maxval=-999999,sum=0;
    int ans;
    for(int i=0;i<n;i++)
    {
        sum+=vec[i];
        maxval=max(vec[i],maxval);
    }
    start=sum;
    end=maxval;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(n, m, mid))   //left
        {
            ans=mid;
            end=mid-1;
        }
        else    //right
        {
            start=mid+1;
        }
    }
    return ans;
}

int main(){

    int n=4,m=2;    //m=painters; n=time to paint each painting
    int result=mintimetopaint(n,m);
    cout<<result<<endl;

    return 0;
}