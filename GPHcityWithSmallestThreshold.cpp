// TC:O(n^3)
// SC:O(n^2)

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // creating the adjacency matrix of the given graph
        const int INF = 1000000000;
        vector<vector<int>> adj(n,vector<int>(n,INF));
        for(int i=0;i<n;i++)
            adj[i][i]=0;
        for(auto& it:edges)
        {
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u][v]=min(adj[u][v], cost);
            adj[v][u]=min(adj[v][u], cost);
        }

        // applying floyd-warshall
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                if (adj[i][k] == INF) continue;
                for(int j=0;j<n;j++)
                {
                    if (adj[k][j] == INF) continue;
                    long long s = (long long)adj[i][k] + adj[k][j];
                    if (s < adj[i][j])
                        adj[i][j] = (int)s;
                }
            }
        }

        // checking for threshold
        int bestCity = -1;
        int minCount = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue; // exclude self
                if (adj[i][j] <= distanceThreshold) ++cnt;
            }
            if (cnt < minCount || (cnt == minCount && i > bestCity)) {
                minCount = cnt;
                bestCity = i;
            }
        }
        return bestCity;
    }
};