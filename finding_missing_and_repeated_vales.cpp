class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            // using unordered set to find the repeating values
    
            vector<int> answer;
            unordered_set<int> m;
            int n=grid.size();
            int a, b;
            int actualsum=0, expectedsum;
    
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    // find the repeating numbers
                    if(m.find(grid[i][j])!=m.end())
                    {
                        a=grid[i][j];
                        answer.push_back(a);
                    }
                    m.insert(grid[i][j]);
    
                    // calculating the actual sum of elements present in the grid
                    actualsum+=grid[i][j];
                }
            }
    
            //finding the missing number
            expectedsum=((n*n)*((n*n)+1))/2;
            b=expectedsum-actualsum+a;
            answer.push_back(b);
    
            return answer;
        }
    };