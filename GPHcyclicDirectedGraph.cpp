// using BFS / Topological Sort
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // creating the adjacency list
        vector<vector<int>> adj(V);
        vector<int> visited(V,0);
        vector<int> indegree(V,0);
        queue<int> q;
        
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
        // check toposort is applied for V vertices or not
        return (count==V?false:true);
    }
};

