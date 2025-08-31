class Solution {
public:
    void dfs(int& node,vector<vector<int>>& matrix, vector<int>& visited){
        visited[node]=1;
        for (int i=0;i<matrix.size();i++)
        {
            if(!visited[i] && matrix[node][i])
            {
                visited[i]=1;
                dfs(i,matrix,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int counter=0;
        for (int i=0;i<isConnected.size();i++)
        {
            if(!visited[i])
            {
                counter++;
                dfs(i,isConnected,visited);
            }
        }
        return counter;
    }
};