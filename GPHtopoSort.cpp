// Toposort
//TC: O(V+E)

class Solution {
  public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj,stack<int>& s){
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
                dfs(it,visited,adj,s);
        }
        s.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> visited(V,0);
        stack<int> s;
        
        for(auto& it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            // adj[v].push_back(u); since it is directed
        }
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                dfs(i,visited,adj,s);
        }
        
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};