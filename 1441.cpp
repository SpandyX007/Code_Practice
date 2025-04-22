class Solution {
    public:
        vector<string> buildArray(vector<int>& target, int n) {
            vector<string> output;
            stack<int> target2;
            stack<int> target2copy;
            int j=0;
            if(target.size()==1)
            {
                output.push_back("Push");
                return output;
            }
            for(int i=1;i<=n;i++)
            {
                output.push_back("Push");
                target2.push(i);
                target2copy.push(i);
                //&& target2.size()!=0
                if(j<target.size() && target[j]!=target2.top())
                {
                    target2.pop();
                    target2copy.pop();
                    output.push_back("Pop");
                }
                else
                {
                    j++;
                    if(target.size()==target2.size())
                    {
                        int k=target2.size();
                        int flag=1;
                        while(!target2copy.empty())
                        {
                            if(target[k-1]==target2copy.top())
                            {
                                target2copy.pop();
                                k--;
                            }
                            else
                                flag=0;
                        }
                        if(flag)
                            return output;
                    }
                }
    
            }
            return output;
        }
    };