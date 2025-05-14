class Solution {
    public:
        bool colBS(vector<vector<int>>& matrix, int midRow, int target,int cols){
            int start=0, end=cols-1;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(matrix[midRow][mid]==target)
                    return true;
                else if(target>matrix[midRow][mid])
                    start=mid+1;
                else if(target<matrix[midRow][mid])
                    end=mid-1;
            }
            return false;
        }
    
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int rows=matrix.size();
            int cols=matrix[0].size();
    
            int low=0, high=rows-1;
            // binary search on the rows
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(matrix[mid][0]<=target && target<=matrix[mid][cols-1])
                {
                    //calling the function to find apply binary search on column
                    return colBS(matrix,mid,target,cols);
                }
                else if(target>=matrix[mid][cols-1])
                    low=mid+1;
                else if(target<=matrix[mid][0])
                    high=mid-1;
            }
            return false;
        }
    };