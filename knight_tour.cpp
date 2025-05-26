class Solution {
public:
    bool helper(vector<vector<int>> &grid, int r, int c, int n, int expval){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expval)
            return false;
        if(grid[r][c]==n*n-1)
            return true;


        //suggesting all possible moves for the knight
        bool ans1=helper(grid,r-2, c+1,n,expval+1);
        bool ans2=helper(grid,r-1, c+2,n,expval+1);
        bool ans3=helper(grid,r+1, c+2,n,expval+1);
        bool ans4=helper(grid,r+2, c+1,n,expval+1);
        bool ans5=helper(grid,r+2, c-1,n,expval+1);
        bool ans6=helper(grid,r+1, c-2,n,expval+1);
        bool ans7=helper(grid,r-1, c-2,n,expval+1);
        bool ans8=helper(grid,r-2, c-1,n,expval+1);

        return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int answer=helper(grid,0,0,n,0);

        return answer;
    }
};