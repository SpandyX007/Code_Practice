// TC: O(n*m)
// SC: O(n*m)

class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        visited[row][col]=1;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        int baseRow=row;
        int baseCol=col;
        while(!q.empty())
        {
            int qrow=q.front().first;
            int qcol=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=qrow+delRow[i];
                int ncol=qcol+delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        int countIsland=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    visited[i][j]=1;
                    bfs(i,j,visited,grid);
                    countIsland++;
                }
            }
        }

        return countIsland;
    }
};