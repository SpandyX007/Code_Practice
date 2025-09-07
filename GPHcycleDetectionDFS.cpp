// Cycle detect in Undirected Grpah
// Using DFS

// TC: O(V*total degree) = O(V*2*E)     SC:O(V*2*E)
class Solution {
  public:
    bool dfs(int node, int parent, vector<vector<int>>& edges, vector<int>& visited){
        visited[node]=1;
        int E=edges.size();
        for(auto it:edges[node])
        {
            if(!visited[it])
            {
                if(dfs(it,node,edges,visited)==true)
                    return true;
            }
            else if(it!=parent)
                return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        int E=edges.size();
        vector<int> visited(V,0);
        vector<vector<int>> adj(V);
        
        //filling values in adjacency list
        for(auto& it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,-1,adj,visited)==true)
                    return true;
            }
        }
        return false;
    }
};

// using BFS
// TC:O(V*total degree)==O(V*2*E)       SC:O(V*2*E)
class Solution {
  public:
    bool bfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited){
        visited[node]=1;
        queue<pair<int,int>> q;
        q.push({node,parent});
        while(!q.empty())
        {
            int currnode=q.front().first;
            int currparent=q.front().second;
            q.pop();
            
            for(auto it:adj[currnode])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    q.push({it,currnode});
                }
                else if(it!=currparent)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // queue<pair<int,int>> q;
        vector<int> visited(V,0);
        vector<vector<int>> adj(V);
        
        //filling the adjacency list
        for(auto& it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // calling bfs by components
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                if(bfs(i,-1,adj,visited))
                    return true;
        }
        
        return false;
    }
};