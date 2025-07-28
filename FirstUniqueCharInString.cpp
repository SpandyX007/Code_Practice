// partially optimised using queue and hashmaps
// can be optimised more using hashmaps and two for loops TC:O(n) and SC:O(1)

// TC:O(n) and SC:O(n)
class Solution {
public:
    // an unordered map and queue to track the index of the characters  
    unordered_map<char,int> m;
    queue<int> q;
    int firstUniqChar(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])==m.end())
            {
                //adding value if not present(unique)
                m[s[i]]=1;
                // storing the index of the char in the queue
                q.push(i);
            }
            else
            {
                //incrementing if existing
                m[s[i]]+=1;
            }
        }
        while(q.size()>=1)
        {
            if(m[s[q.front()]]>1)
                q.pop();
            else
                break;
        }
        if(!q.empty())
            return q.front();
        return -1;
    }
};