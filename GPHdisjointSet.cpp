#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;
public:
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


int main(){

    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    // if 3 and 7 same or not
    if(ds.findUlParent(3)==ds.findUlParent(7))
        cout<<"Same"<<endl;
    else
        cout<<"Not Same"<<endl;
    ds.unionByRank(3,7);

    if(ds.findUlParent(3)==ds.findUlParent(7))
        cout<<"Same"<<endl;
    else
        cout<<"Not Same"<<endl;

    return 0;
}