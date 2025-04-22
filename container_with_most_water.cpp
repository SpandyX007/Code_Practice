#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> vec={1,8,6,2,5,4,8,3,7};

int bruteforce(){
    int width=0, height=0, area=0, maxwater=0;
    for(int i=0;i<vec.size();i++)
    {
        for(int j=i+1;j<vec.size();j++)
        {
            width=j-i;
            height=min(vec[i],vec[j]);
            area=width*height;
            maxwater=max(maxwater,area);
        }
    }
    return maxwater;
}

int twopointer(){
    int lp=0, rp=vec.size()-1, width=0, height=0, area=0, maxwater=0;
    while(lp<rp)
    {
        width=rp-lp;
        height=min(vec[lp],vec[rp]);
        area=width*height;
        maxwater=max(area,maxwater);
        vec[lp]<vec[rp]?lp++:rp--; //if lp is less increase lp else decrease rp
    }
}

int main(){

    int result=bruteforce();
    cout<<result;

    return 0;
}