//TC:O(logn)

// TC:O(nlogn)
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // counting the number of zeros
        int count0=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
                count0++;
            else
                arr.push_back(arr[i]);
        }
        
        // putting the zeros in the backside
        for(int i=0;i<count0;i++)
            arr.push_back(0);
        
        //removing the zeros from the fornt
        arr.erase(arr.begin()+0,arr.begin()+n);
        
    }
};