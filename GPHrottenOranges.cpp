class Solution {
public:
    int orangesRotting(vector<vector<int>>& matrix) {
        int n=matrix.size();    //row
        int m=matrix[0].size(); //col
        vector<vector<int>> visited(n,vector<int>(m,0));
        // q{{x,y},time}
        int fresh=0;    // counting fresh oranges values
        queue<pair<pair<int,int>,int>> q;
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else
                    visited[i][j]=0;
                    // checking if the orange is fresh or not
                if (matrix[i][j]==1)
                    fresh++;
            }
        }

        int rotten=0;
        int tm=0;
        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,-1,0,1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            tm=max(tm,time);
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && matrix[nrow][ncol]==1 && visited[nrow][ncol]!=2)
                {
                    visited[nrow][ncol]=2;
                    q.push({{nrow,ncol},time+1});
                    rotten++;
                }
            }
        }

        if (rotten!=fresh)
            return -1;
        return tm;
    }
};