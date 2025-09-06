// User function Template for C++

//TC:O(n^2)     SC:O(n^2)

class Solution {
  public:
    void bfs(int row,int col,vector<vector<int>>& visited,vector<vector<int>>& grid,vector<pair<int,int>>& shape){
        queue<pair<int,int>> q;
        visited[row][col]=1;
        q.push({row,col});
        
        int delRow[]={0,-1,0,1};
        int delCol[]={-1,0,1,0};
        int n=grid.size();
        int m=grid[0].size();
        
        // store the original coordinates
        int baseRow=row;
        int baseCol=col;
        
        while(!q.empty())
        {
            int qrow=q.front().first;
            int qcol=q.front().second;
            q.pop();
            
            //store the relative postision
            shape.push_back({qrow-baseRow,qcol-baseCol});
            for(int i=0;i<4;i++)    
            {
                int nrow=qrow+delRow[i];
                int ncol=qcol+delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<int>> visited(n,vector<int>(m,0));
        int counter=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>> shape;    //shape vector to keep track of shape of the island
                    bfs(i,j,visited,grid,shape);
                    s.insert(shape);    //insert the shape in the set
                }
            }
        }
        
        return s.size();
    }
};
