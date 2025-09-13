// TC: O(ElogV)
// SC: O(V+E)

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // converitng it ot adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(auto& it:edges)
        {
            int u=it[0];
            int v=it[1];
            int distance=it[2];
            adj[u].push_back({distance,v});
            adj[v].push_back({distance,u});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dist(V, INT_MAX);
        dist[src]=0;
        q.push({0,src});
        
        while(!q.empty())
        {
            int distance=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto it:adj[node])
            {
                if(distance+it.first<dist[it.second])
                {
                    dist[it.second]=distance+it.first;
                    q.push({distance+it.first,it.second});
                }
            }
        }
        
        return dist;
    }
};