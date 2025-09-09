class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // applying normal DFS in the matrix
        // we will apply Dijikstra Algo but priority queue is not needed because there is unit distances

        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;   //{cost,{row,col}}
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        if(grid[0][0]==1)
            return -1;
        else if(grid[n-1][m-1]==1)
            return -1;

        q.push({0,{0,0}});  //inserting the source;
        dist[0][0]=0;
        pair<int,int> des={n-1,m-1};
        
        while(!q.empty())
        {
            int cost=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();

            if (row == n-1 && col == m-1) 
                return cost;

            int delRow[]={-1,0,1,0,-1,-1,1,1};
            int delCol[]={0,-1,0,1,-1,1,1,-1};
            for(int i=0;i<8;i++)
            {
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && dist[nrow][ncol]==INT_MAX && grid[nrow][ncol]==0)
                {
                    dist[nrow][ncol]=cost+1;
                    q.push({1+cost,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};