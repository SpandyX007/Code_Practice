class Solution {
public:
    void toposort(vector<vector<int>>& adj, vector<int>& topoOrder) {
        queue<int> q;
        vector<int> indegree(26, 0);
        
        for(int i=0;i<26;i++)
            for(auto it: adj[i])
                indegree[it]++;
        
        for(int i=0;i<26;i++)
            if(indegree[i]==0) q.push(i);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
    }
    
    string findOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        vector<int> topoOrder;
        vector<bool> present(26, false);
        
        for(auto &word: words) {
            for(char c: word) present[c-'a'] = true;
        }
        
        int totalwords = words.size();
        for(int i=0;i<totalwords-1;i++) {
            string s1=words[i];
            string s2=words[i+1];
            int minlenstr = min(s1.size(), s2.size());
            
            if(s1.size() > s2.size() && s1.substr(0, minlenstr) == s2.substr(0, minlenstr))
                return ""; // invalid order
            
            for(int j=0;j<minlenstr;j++) {
                if(s1[j]!=s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        toposort(adj, topoOrder);
        
        // after toposort
        string ans="";
        for(int it: topoOrder) {
            if(present[it]) ans += char(it+'a');
        }
        
        // cycle detection: if not all present characters are in topoOrder
        int countPresent = 0;
        for(bool p: present) if(p) countPresent++;
        
        if(ans.size() < countPresent) return ""; // invalid (cycle exists)
        
        return ans;
    }
};
