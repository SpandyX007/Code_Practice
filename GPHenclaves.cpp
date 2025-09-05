// similar to surrounding problem
class Solution {
public:
    void bfs(vector<vector<int>>& visited,vector<vector<int>>& grid,queue<pair<int,int>>& q){
        int n=grid.size(); 
        int m=grid[0].size();
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            visited[row][col]=1;
            q.pop();
            //traverse all four directions
            for(int i=0;i<4;i++)
            {
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();  //row
        int m=grid[0].size();    //cols
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int enclosed=0;

        // traversing the top and the botton row
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
            {
                visited[0][i]=1;
                q.push({0,i});
            }
            if(grid[n-1][i]==1)
            {
                visited[n-1][i]=1;
                q.push({n-1,i});
            }
        }

        //traversing the left and right side
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                visited[i][0]=1;
                q.push({i,0});
            }
            if(grid[i][m-1]==1)
            {
                visited[i][m-1]=1;
                q.push({i,m-1});
            }
        }

        bfs(visited,grid,q);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                    enclosed++;
            }
        }

        return enclosed;
    }
};