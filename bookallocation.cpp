#include <iostream>
#include <vector>
using namespace std;

//time complexity=O(nlogn)

vector<int> vec={2,1,3,4};
int books=4;
int students=2;

bool isvalid(int start,int end,int maxAllowedpages){
    int studs=1, pages=0;

    for(int i=0 ;i<students;i++)    //O(n)
    {
        if(vec[i]>maxAllowedpages)
            return false;
        if(pages+vec[i]<=maxAllowedpages)
            pages+=vec[i];
        else
        {
            studs++;
            pages=vec[i];
        }
    }

    return students>students?false:true;
}

int main(){

    if(students>books)
        cout<<"not possible";
    int sum=0;
    for (int i=0;i<vec.size();i++)
        sum+=vec[i];
    int start=0, end=sum, ans=-1;
    while(start<=end)   //O(logn)
    {
        int mid=start+(end-start)/2;
        if(isvalid(start, end, mid))
        {
            ans=mid;
            end=mid-1;
        }
    }

    cout<<ans;

    return 0;
}