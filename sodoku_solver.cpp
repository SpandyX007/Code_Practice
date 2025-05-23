class Solution {
    public:
        bool isSafe(vector<vector<char>>& board, int row, int col, char digit){
            // horizontal check
            for(int i=0;i<9;i++)
                if(board[row][i]==digit)
                    return false;
            
            //vertical check 
            for(int i=0; i<9; i++)
                if(board[i][col]==digit)
                    return false;
            
            //checking in the grid
            int srow, scol;      //starting row and col for the grid
            srow=(row/3)*3;
            scol=(col/3)*3;
            for(int i=srow;i<=srow+2;i++)
                for(int j=scol;j<=scol+2;j++)
                    if(board[i][j]==digit)
                        return false;
            
            return true;
        }
        bool helper(vector<vector<char>>& board, int row, int col){
            if(row==9)
                return true;
        
            int nextrow=row, nextcol=col+1;
            if(nextcol==9)
            {
                nextrow=row+1;
                nextcol=0;
            }
    
            //if number is already in the row/col
            if(board[row][col]!='.')
                return helper(board,nextrow,nextcol);
            //if no number is present in the row/col
            for(char digit='1';digit<='9';digit++)
            {
                if(isSafe(board, row, col, digit))
                {
                    board[row][col]=digit;
                    if(helper(board, nextrow, nextcol))
                        return true;
                    board[row][col]='.';
                }
            }
            return false;
        }
        void solveSudoku(vector<vector<char>>& board) {
            helper(board, 0, 0);
        }
    };