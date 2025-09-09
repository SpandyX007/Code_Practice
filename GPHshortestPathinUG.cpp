class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        //appplying normal BFS to get tothe shortest path
        int n=adj.size();
        vector<int> dist(n,-1);
        queue<pair<int,int>> q;
        
        q.push({src,0});
        dist[src]=0;
        while(!q.empty())
        {
            int node=q.front().first;
            int distance=q.front().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                if(dist[it]==-1)
                {
                    dist[it]=distance+1;
                    q.push({it,dist[it]});
                }
            }
        }
        
        return dist;
    }
};