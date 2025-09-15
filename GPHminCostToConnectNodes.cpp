//TC:O(n^2logn)
//SC:O(n)

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points){
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> visited(n,0);

        // initial steps to implement
        q.push({0,0});  //{cost,node}
        int sum=0;

        while(!q.empty())
        {
            int node=q.top().second;
            int weight=q.top().first;
            q.pop();

            if(visited[node])
                continue;
            visited[node]=1;

            sum+=weight;

            for(int i=0;i<n;i++)
            {
                if(!visited[i])
                {
                    int adjWt=abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                    q.push({adjWt,i});
                }
            }
        }

        return sum;
    }
};