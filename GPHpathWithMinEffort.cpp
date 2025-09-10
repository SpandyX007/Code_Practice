//TC: O(E*logV) i.e (n x m x 4 x log(n x m))

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // applying plain Dijkstra's Algo to find the optimal path
        // let's apply BFS and test
        int n=heights.size();
        int m=heights[0].size();
        // Min-heap priority queue
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > q;
        vector<vector<int>> absdistance(n,vector<int>(m,INT_MAX));

        absdistance[0][0]=0;
        q.push({0,{0,0}});

        while(!q.empty())
        {
            int nodecost=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;
            q.pop();

            if(row==n-1 && col==m-1)
                return nodecost;

            int delRow[]={-1,0,1,0};
            int delCol[]={0,-1,0,1};
            for(int i=0;i<4;i++)
            {
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int newEffort=max(abs(heights[row][col]-heights[nrow][ncol]),nodecost);
                    if(newEffort<absdistance[nrow][ncol])
                    {
                        absdistance[nrow][ncol]=newEffort;
                        q.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }

        return 0;
    }
};