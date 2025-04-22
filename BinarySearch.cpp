#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int> arr, int target){
    //time complexity= O(log n) and Space complexity=O(1)
    int start=0, end=arr.size()-1;

    while(start<=end)
    {
        int mid=(start+end)/2;
        
        if(target<arr[mid])
        {
            end=mid-1;
        }
        else if(target>arr[mid])
        {
            start=mid+1;
        }
        else
            return mid;
    }
    return -1;
}

int binarysearchoptimised(vector<int> arr, int target){
    //time complexity= O(log n) and Space complexity=O(1)
    //if we consider the max value of both 'start' and 'end' that is INI_MAX, then it is impossible to store the value of (start+end)/2 in 'mid' due to overflow condition. Therefore we consider the following to avoid the error

    int start=0, end=arr.size()-1;

    while(start<=end)
    {
        int mid=start+(end-start)/2;    // it is mathematically the same as (start+end)/2
        
        if(target<arr[mid])
        {
            end=mid-1;
        }
        else if(target>arr[mid])
        {
            start=mid+1;
        }
        else
            return mid;
    }
    return -1;
}

int RecurssiveBS(vector<int> arr, int target, int start, int end){
    //Time cmplexity=O(n) and Space complexity=O(n)
    if(start<=end)
    {
        int mid=start+(end-start)/2;
        if(target<arr[mid])
        {
            return RecurssiveBS(arr,target,start,mid-1);
        }
        else if(target>arr[mid])
        {
            return RecurssiveBS(arr,target,mid+1,end);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main(){

    //odd array
    vector<int> list1={1,2,3,4,5,6,7,8,9};
    int target1=7;

    int result1=binarysearch(list1,target1);
    cout<<"The element found at index by binarysearch: "<<result1<<endl;

    result1=binarysearchoptimised(list1,target1);
    cout<<"The element found at index by binarysearchoptimised: "<<result1<<endl;

    //even array
    vector<int> list2={1,2,3,4,5,6,7,8};
    int target2=7;

    int result2=binarysearch(list2,target2);
    cout<<"The element found at index by binarysearch: "<<result2<<endl;

    result2=binarysearchoptimised(list2,target2);
    cout<<"The element found at index by binarysearchoptimised: "<<result2<<endl;

    int result3=RecurssiveBS(list2,target2,0,list2.size()-1);
    cout<<"The element found at index by Recurssive Binary Search is: "<<result3<<endl;

    return 0;
}