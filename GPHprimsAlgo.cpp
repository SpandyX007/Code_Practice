//TC: O(E log E) + O(E log E) i.e traversing from priorityQ + iterating over adjList
//SC: O(N)

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // creating the adjacency node
        vector<vector<pair<int,int>>> adj(V);
        for (auto& it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        // priority queue and visited initialisation
        vector<int> visited(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;    //{wt,node}
        q.push({0,0});
        
        int sum=0;
        while(!q.empty())
        {
            int node=q.top().second;
            int weight=q.top().first;
            q.pop();
            
            if(visited[node]==1)
                continue;
            visited[node]=1;
            sum+=weight;
            
            for(auto& it:adj[node])
            {
                int adjNode=it.first;
                int adjWt=it.second;
                if(!visited[adjNode])
                    q.push({adjWt,adjNode});
            }
        }
        return sum;
    }
};