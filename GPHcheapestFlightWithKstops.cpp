//TC: O(E)  E=no. of fights

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // since they told about cheap cost, we will apply Dijikstra Algo to reach the destination with k stops

        queue<pair<int,pair<int,int>>> q;    //{dist,node,stops}

        vector<vector<pair<int,int>>> adj(n);   //{dest,cost}
        vector<int> distance(n,INT_MAX);

        // forming the adjacency list
        for(auto& it:flights)
        {
            int u=it[0];
            int v=it[1];
            int price=it[2];
            adj[u].push_back({v,price});
        }

        // initialising source node with 0
        distance[src]=0;
        q.push({0,{src,0}});    //{stops,{src,cost}}

        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k)
                continue; 

            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int weight=it.second;
                if(cost+weight<distance[adjNode] && stops<=k)
                {
                    distance[adjNode]=cost+weight;
                    q.push({stops+1,{adjNode,cost+weight}});
                }
            }
        }

        return (distance[dst]==INT_MAX?-1:distance[dst]);

    }
};