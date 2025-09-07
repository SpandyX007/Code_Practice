// Toposort
//Using DFS TC: O(V+E)

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

// Using Kahn's Algorithm
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> visited(V,0);
        vector<int> indegree(V,0);
        
        for(auto& it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            // now that node is in the ans, 
            // remove it from the indegree
            for(auto it:adj[node])
            {
                indegree[it]--; // reducing the connected nodes by 1
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return ans;
    }
};