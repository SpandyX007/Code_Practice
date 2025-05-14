class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int rows=matrix.size(), cols=matrix[0].size();
            int start=0, end=cols-1;
    
            while(start<rows && end>=0)
            {
                if(target==matrix[start][end])
                    return true;
                else if(target<matrix[start][end])
                    end--;
                else
                    start++;
            }
            return false;
        }
    };