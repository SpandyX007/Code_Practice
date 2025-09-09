// User function Template for C++
class Solution {
    void dfs(int node,stack<int>& s,vector<int>& visited, vector<vector<pair<int,int>>>& adj){
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it.first])
            {
                dfs(it.first,s,visited,adj);
            }
        }
        s.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Apply topoSort in DFS mode and apply BFS shortest path algo
        vector<vector<pair<int,int>>> adj(V);
        int src=0;
        
        // the edges to adjacency list
        // 0 ->{1,2}    i.e     node->{adjacent_node,cost}
        
        // creating adjacent list
        for(auto& it:edges)
        {
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
        
        // find topoSort
        // O(V+E)
        vector<int> visited(V,0);
        stack<int> s;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                dfs(i,s,visited,adj);
        }
        
        // step 2 do the distance thing
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        // O(V+E)
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            if(dist[node]!=INT_MAX) //relax iff reachable
            {
                for(auto it:adj[node])
                {
                    int vertex=it.first;
                    int wt=it.second;
                    if(dist[node]+wt<dist[vertex])  //edge relaxation
                        dist[vertex]=dist[node]+wt;
                }
            }
        }
        
        for(int i=0;i<V;i++)
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        
        return dist;
        
        
    }
};
