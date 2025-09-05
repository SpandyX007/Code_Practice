// interview solution
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        queue<vector<string>> q;
        vector<vector<string>> ans;
        vector<string> currans;
        unordered_set<string> s(wordList.begin(),wordList.end());
        
        currans.push_back(beginWord);
        q.push(currans);
        s.erase(beginWord);
        int level=0;
        
        while(!q.empty())
        {
            // accessing the last element of the vector from queue
            vector<string> vec=q.front();
            q.pop();
            // erase all words that has been used in tehthe previous levels to transform
            if(vec.size()>level)
            {
                level++;
                for(auto it:currans)
                    s.erase(it);
                currans.clear();
            }
            string word=vec.back();
            
            if(word==endWord)
            {
                // the first sequence where we reached end
                if(ans.size()==0)
                    ans.push_back(vec);
                else if(ans[0].size()==vec.size())
                    ans.push_back(vec);
            }
            
            for(int i=0;i<word.size();i++)
            {
                char original=word[i];
                for(char j='a';j<='z';j++)
                {
                    word[i]=j;
                    if(s.find(word)!=s.end())
                    {
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited on the level
                        currans.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};