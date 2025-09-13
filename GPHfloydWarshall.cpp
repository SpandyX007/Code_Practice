// User function template for C++

// TC: O(n^3)
// SC: O(n^2)

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int V=dist.size();
        for(int via=0;via<V;via++)
        {
            for(int i=0;i<V;i++)
            {
                for(int j=0;j<V;j++)
                {
                    if(dist[i][via]!=1e8 && dist[via][j]!=1e8)
                        dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
    }
};