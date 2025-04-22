// given target should match with what pair of elements in the given array

#include <iostream>
using namespace std;

int brutteforce(int arr[], int target, int n){
    
    for(int start=0;start<n;start++)
    {
        for(int end=start+1;end<n;end++)
        {
            int sum=arr[start]+arr[end];
            if(sum==target)
                cout<<"The pairs are: "<<arr[start]<<" "<<"and "<<arr[end]<<endl;
        }
    }
}

//optimised solution
int optimised(int arr[], int target, int n){
    // two pointer approach
    int i=0, j=n-1;
    while(i<j)
    {
        int sum=arr[i]+arr[j];
        if(sum>target)
            j--;
        else if(sum<target)
            i++;
        else
        {
            cout<<"The pairs are: "<<arr[i]<<" "<<"and "<<arr[j]<<endl;
            break;
        }
    }
}

int main(){

    int n=4;
    int target=9;
    int arr[n]={2,7,11,15};
    brutteforce(arr, target, n);
    optimised(arr, target, n);

    return 0;
}