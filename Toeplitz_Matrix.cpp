class Solution {
    public:
        bool isToeplitzMatrix(vector<vector<int>>& matrix) {
            int row=matrix.size();
            int col=matrix[0].size();
    
            //traversing in the same row
            for(int k=0; k<col; k++)
            {
                int i=0,j=k;
                int val=matrix[i][j];
                while(i<row && j<col)
                {
                    if(val!=matrix[i][j])
                        return false;
                    i++;j++;                 
                }
            }
    
            //traversing in the same column
            for(int k=1; k<row; k++)
            {
                int i=k,j=0;
                int val=matrix[i][j];
                while(i<row && j<col)
                {
                    if(val!=matrix[i][j])
                        return false;
                    i++;j++;               
                }
            }
    
            return true;        
        }
    };