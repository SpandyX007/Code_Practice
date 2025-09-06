class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color){
        color[node]=col;
        for(int i=0; i<graph[node].size();i++)
        {
            int nextNode=graph[node][i];
            if(color[nextNode]==-1)
            {
                if(dfs(nextNode, !col, graph, color)==false)
                    return false;
            }
            else if(color[nextNode]==col)
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int nodes=graph.size();
        vector<int> color(nodes,-1);

        for(int i=0;i<nodes;i++)
        {
            if(color[i]==-1)
                if(dfs(i,0,graph,color)==false)
                    return false;
        }

        return true;
    }
};