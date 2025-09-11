//TC: O(ElogV)
// SC: O(V+E)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // creating the adjacency list
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& it:times)
        {
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }

        vector<int> distance(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;     //{wt,node}
        distance[k]=0;
        q.push({0,k});
        

        while(!q.empty())
        {
            int weight=q.top().first;
            int node=q.top().second;
            q.pop();
            if(weight>distance[node])
                continue;
            for(auto& it:adj[node])
            {
                int nextNode=it.first;
                int nextWt=it.second;
                if(weight+nextWt<distance[nextNode])
                {
                    distance[nextNode]=weight+nextWt;
                    q.push({weight+nextWt,nextNode});
                }
            }
        }

        int maxTime=0;
        for(int i=1;i<distance.size();i++)
        {
            if(distance[i]==INT_MAX)
                return -1;
            maxTime=max(maxTime,distance[i]);
        }
        return maxTime;
    }
};