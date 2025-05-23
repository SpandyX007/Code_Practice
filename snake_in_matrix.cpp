class Solution {
    public:
        int finalPositionOfSnake(int n, vector<string>& commands) {
            vector<vector<int>> grid(n,vector<int>(n));
            int srow=0, scol=0;
    
            int position=0;
            for(auto command:commands)
            {
                if(command == "UP")
                    position=position-n;
                else if (command == "DOWN")
                    position=position+n;
                else if(command == "LEFT")
                    position=position-1;
                else if(command == "RIGHT")
                    position=position+1;
            }
            return position;
        }
    };