/*
arr={1,2,3,4,5};
subarrays= [
            {1},{1,2},{1,2,3},{1,2,3,4},{1,2,3,4,5}
            {2},{2,3},{2,3,4},{2,3,4,5}
            {3},{3,4},{3,4,5}
            {4},{4,5}
            {5}
            ]
*/

#include <iostream>
#define SIZE 5
using namespace std;

int arr[SIZE]={1,2,3,4,5};

int printallsubarrays(){
    // printing all the subarrays
    for(int start=0;start<SIZE;start++)
    {
        for(int end=start;end<SIZE;end++)
        {
            for(int i=start;i<=end;i++)
            {
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

int bruteforce(){
    int maxsum=-999999999;
    for(int start=0;start<SIZE;start++)
    {
        int currsum=0;
        for(int end=0;end<SIZE;end++)
        {
            currsum+=arr[end];
            maxsum=max(maxsum,currsum);
        }
    }
    return maxsum;
}

int kadensalgo(){
    int maxsum=-99999999;
    int currsum=0;
    for (int i=0; i<SIZE; i++)
    {
        currsum+=arr[i];
        maxsum=max(currsum,maxsum);
        if(currsum<0)
        {
            currsum=0;
        }
    }

    return maxsum;
}

int main(){   

    //printallsubarrays();
    // int subarraysum=bruteforce();
    int subarraysum=kadensalgo();
    cout<<subarraysum;

    return 0;
}