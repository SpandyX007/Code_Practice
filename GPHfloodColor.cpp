class Solution {
public:
    void dfs(vector<vector<int>>& matrix, int& row, int& col, int& color, int& prevColor, int delRow[],int delCol[] ){
        // visited[row][col]=1;
        matrix[row][col]=color;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(ncol>=0 &&  ncol<m && nrow>=0 && nrow<n && matrix[nrow][ncol]==prevColor)
                dfs(matrix,nrow,ncol,color,prevColor,delRow,delCol);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;

        int n=image.size();
        int m=image[0].size();
        // vector<vector<int>> visited(n,vector<int>(m,0));
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        int prevColor=image[sr][sc];
        
        // visited[sr][sc]=1;
        dfs(image,sr,sc,color,prevColor,delRow,delCol);

        return image;

    }
};