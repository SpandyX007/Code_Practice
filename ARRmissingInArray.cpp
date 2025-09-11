// TC:O(n)
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // Apllying XOR method
        // a^a =0 
        // a^0=a
        //(1^2^3^4^5)^(1^2^3^5) = 4
        
        int n=arr.size()+1;
        int x=0;
        for(int i=0;i<=n;i++)
            x^=i;
        
        for(auto it:arr)
            x^=it;
            
        return x;
    }
};

// TC:O(nlogn)
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // sorting
        sort(arr.begin(),arr.end());
        
        // find the missing number
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            if(i+1!=arr[i])
                return i+1;
        }
        
        return n+1;
    }
};