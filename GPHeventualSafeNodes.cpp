// TC: O(V+E+nlogn)
// SC: O(V+E)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //reverse the graph and topoSort it to get the safe nodes
        int V=graph.size();
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V,0);

        for(int i=0;i<V;i++)
        {
            int conn=graph[i].size();
            for(int j=0;j<conn;j++)
            {
                adjRev[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            ans.push_back(node);
            for(auto it:adjRev[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};