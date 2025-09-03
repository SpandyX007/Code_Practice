class Solution {
public:
    void dfs(vector<vector<int>>& visited,vector<vector<char>>& board,int row, int col,int delRow[], int delCol[]){
        visited[row][col]=1;
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O')
                dfs(visited,board,nrow,ncol,delRow,delCol);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        // traversing the top and bottom boundary
        for(int i=0;i<m;i++)
        {
            // first row
            if(!visited[0][i] && board[0][i]=='O')
            {
                visited[0][i]=1;
                dfs(visited,board,0,i,delRow,delCol);
            }
            // last row
            if(!visited[n-1][i] && board[n-1][i]=='O')
            {
                visited[n-1][i]=1;
                dfs(visited,board,n-1,i,delRow,delCol);
            }
        }

        //traversing the left and right boundary
        for(int i=0;i<n;i++)
        {
            // left
            if(!visited[i][0] && board[i][0]=='O')
            {
                visited[i][0]=1;
                dfs(visited,board,i,0,delRow,delCol);
            }
            // right 
            if(!visited[i][m-1] && board[i][m-1]=='O')
            {
                visited[i][m-1]=1;
                dfs(visited,board,i,m-1,delRow,delCol);
            }
        }

        // traversing the whole board to surround
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !visited[i][j])
                    board[i][j]='X';
            }
        }

    }
};