// TC: O(N∗MLog(N∗M))
// SC: O(N*M)

class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int findUlParent(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUlParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int UlParentU=findUlParent(u);
        int UlParentV=findUlParent(v);
        if(UlParentU==UlParentV)
            return;
        else if(size[UlParentU]<size[UlParentV])
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> m;
        int n=accounts.size();
        DisjointSet ds(n);
        // mapping the given accounts in a unorederd map
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                if(m.find(mail)==m.end())  // not exsists
                    m[mail]=i;  //add to the map
                else
                    ds.unionBySize(i,m[mail]);
            }
        }

        // merging the emails and returning the array
        vector<vector<string>> mergedMail(n);
        for(auto it:m)
        {
            string mail=it.first;
            int node=ds.findUlParent(it.second);
            mergedMail[node].push_back(mail); // inserting the email for the particular name
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(mergedMail[i].size()==0)
                continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i])
                temp.push_back(it); // creating one array
            
            ans.push_back(temp);    //placing into ans
        }

        return ans;
    }
};