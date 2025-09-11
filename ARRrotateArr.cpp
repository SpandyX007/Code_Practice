// most optimal

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        d=d%arr.size();
        // reverse the array till d
        reverse(arr.begin(),arr.begin()+d);
        // reverse the array after d
        reverse(arr.begin()+d,arr.end());
        // reverse the entire array
        reverse(arr.begin(),arr.end());
    }
};

// not optimal, costly erase is used
// rotated from left side

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int sizearr=arr.size();
        int newd=d%sizearr;
        for(int i=0;i<newd;i++)
        {
            int num=arr[i];
            arr.push_back(num);
        }
        arr.erase(arr.begin(),arr.begin()+d);
    }
};