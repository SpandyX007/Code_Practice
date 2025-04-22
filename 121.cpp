// look into this for the brute force method

#include <iostream>
#include <vector>
using namespace std;


vector <int> vec={7,1,5,3,6,4};
int buyprice=-1;
int sellprice=-1;
int profit=0;

int buy(){
    for (int i=0;i<vec.size();i++)
    {
        for (int j=i+1;j<vec.size();j++)
        {
            if(vec[i]<vec[j])
            {
                buyprice=vec[i];
                return buyprice;
            }
        }
    }
}

int main(){
    
    int buyresult=buy();
    cout<<buyresult<<endl;

    return 0;
}