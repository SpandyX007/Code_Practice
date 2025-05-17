class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> answer;
            int rows=matrix.size();
            int cols=matrix[0].size();
            int srow=0, scol=0, erow=rows-1, ecol=cols-1;
    
            while(srow<=erow && scol<=ecol)
            {
                //top
                for(int i=scol;i<=ecol;i++)
                    answer.push_back(matrix[srow][i]);
                //right
                for(int i=srow+1; i<=erow; i++)
                    answer.push_back(matrix[i][ecol]);
                
                //bottom
                for(int i=ecol-1; i>=scol; i--)
                {
                    if(srow==erow)
                        break;
                    answer.push_back(matrix[erow][i]);
                }
                
                //left
                for(int i=erow-1;i>=srow+1;i--)
                {
                    if(scol==ecol)
                        break;
                    answer.push_back(matrix[i][scol]);
                }
    
                srow++; erow--; scol++; ecol--;
            }
            return answer;
        }
    };