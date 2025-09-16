class DisjointSet{
public:
    vector<int> rank,parent,size;
    // constructor to initialise the parent array
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    // find the ultimate parent
    int findUlParent(int node){
        if(node==parent[node])
            return node;
        return  parent[node]=findUlParent(parent[node]);
    }
    
    // apply union to check if they are connected or not
    void unionByRank(int u,int v){
        int UlParentU=findUlParent(u);
        int UlParentV=findUlParent(v);
        if(UlParentU==UlParentV)
            return;
        if(rank[UlParentU]<rank[UlParentV])
            parent[UlParentU]=UlParentV;    // smaller gets attached to the bigger rank
        else if(rank[UlParentU]>rank[UlParentV])
            parent[UlParentV]=UlParentU;
        else
        {
            parent[UlParentV]=UlParentU;
            rank[UlParentU]++;
        }
    }

    // apply union by size
    void unionBySize(int u,int v){
        int UlParentU=findUlParent(u);
        int UlParentV=findUlParent(v);
        if(UlParentU==UlParentV)
            return;
        if(size[UlParentU]<size[UlParentV])
        {
            parent[UlParentU]=UlParentV;
            size[UlParentV]+=size[UlParentU];
        }
        else
        {
            parent[UlParentV]=UlParentU;
            size[UlParentU]+=size[UlParentV];
        }
    }
        
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // counting the number of extra edges
        DisjointSet ds(n);
        int countExt=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findUlParent(u)==ds.findUlParent(v))
                countExt++;
            else
                ds.unionByRank(u,v);
        }

        // counting the connected components
        int countC=0;
        for(int i=0;i<n;i++)
            if(ds.parent[i]==i)
                countC++;
        int ans=countC-1;
        if(countExt>=ans)
            return ans;
        return -1;
    }
};