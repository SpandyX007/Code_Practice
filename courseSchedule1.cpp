// TC: O(V+E)       SC:O(V+E)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //creating the graph from given matrix
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto it:prerequisites)
        {
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        int counter=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            counter++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }

        return (counter==numCourses?true:false);

    }
};