// my brute force method
class Solution {
    public:
        int diagonalSum(vector<vector<int>>& mat) {
            int row=mat.size();
            int col=mat[0].size();
            int sum=0;
    
            // if matrix has even order
            if(row%2==0)
            {
                for(int i=0,j=0;i<row && j<col;i++,j++)
                    sum+=mat[i][j];
                for(int i=0,j=col-1;i<row && j>=0;i++,j--)
                    sum+=mat[i][j];
            }
            else
            {
                for(int i=0,j=0;i<row && j<col;i++,j++)
                    sum+=mat[i][j];
                for(int i=0,j=col-1;i<row && j>=0;i++,j--)
                {
                    if(i==j)
                        continue;
                    sum+=mat[i][j];
                }
            }
            
            return sum;
        }
    };

// Optimsed Time complexity
class Solution {
    public:
        int diagonalSum(vector<vector<int>>& mat) {
            int n=mat.size();
            int digsum=0;
    
            for(int i=0;i<n;i++)
            {
                digsum+=mat[i][i];  //add the elements of the primary diagonal
    
                //automatic exclusion the common elemnt in case of odd order matrix
                if(i!=n-i-1)        //add the element of the seconday diagonal
                    digsum+=mat[i][n-i-1];
            }
            
            return digsum;
        }
    };