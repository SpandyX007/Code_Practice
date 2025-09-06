// interview solution

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



// CP approach for LeetCode
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> depthMap;
        vector<vector<string>> ans;
        
        // BFS to find the shortest path
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        depthMap[beginWord] = 1;
        wordSet.erase(beginWord);
        
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = depthMap[word];
            if (word == endWord) break;
            for (int i = 0; i < word.size(); ++i) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;
                    if (wordSet.count(word)) {
                        q.push(word);
                        wordSet.erase(word);
                        depthMap[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        
        // DFS to find all paths
        if (depthMap.count(endWord)) {
            vector<string> seq = {endWord};
            dfs(endWord, beginWord, seq, depthMap, ans);
        }
        
        return ans;
    }
    
private:
    void dfs(string word, string beginWord, vector<string>& seq, unordered_map<string, int>& depthMap, vector<vector<string>>& ans) {
        if (word == beginWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        
        int steps = depthMap[word];
        for (int i = 0; i < word.size(); ++i) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                if (depthMap.count(word) && depthMap[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, beginWord, seq, depthMap, ans);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
};