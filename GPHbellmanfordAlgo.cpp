// User function Template for C++
// TC: O(V x E)
// SC: O(N)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // applying n-1 iterations to relax the nodes
        vector<int> distance(V,1e8);
        distance[src]=0;
        for(int i=0;i<V-1;i++)
        {
            for(auto it:edges)
            {
                int u=it[0];
                int v=it[1];
                int dist=it[2];
                if(distance[u]!=1e8 && dist+distance[u]<distance[v])
                    distance[v]=dist+distance[u];
            }
        }
        
        // nth relaxation to check negative cycles
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int dist=it[2];
            if(distance[u]!=1e8 && dist+distance[u]<distance[v])
                return {-1};
        }
        
        return distance;
    }
};
