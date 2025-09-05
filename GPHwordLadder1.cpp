class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // copying the wordList into a set
        unordered_set<string> s(wordList.begin(),wordList.end());
        // queue({word,transformation value})
        queue<pair<string,int>> q;
        int transCount=0;

        s.erase(beginWord);
        q.push({beginWord,1});


        while(!q.empty())
        {
            string word=q.front().first;
            transCount=q.front().second;
            q.pop();
            // this for loop is for traversing each letter of the word
            if(word==endWord)
                return transCount;
            for(int i=0;i<word.size();i++)
            {
                // this for loop is for generating char(a to z)
                char original=word[i];
                for(int j=97;j<=122;j++)
                {
                    word[i]=char(j);
                    // it exsist in the set
                    if(s.find(word)!=s.end())
                    {
                        s.erase(word);
                        q.push({word,transCount+1});
                    }
                    
                }
                word[i]=original;
            }
        }
        return 0;
    }
};