class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        stack<int> s;
        int n=mat.size();
        // inserting the values(persons) into the stack
        for (int i=0;i<n;i++)
            s.push(i);
            
        
        //checking if the pair of persons is a celebrity or not until one persons remains in the stack
        while(s.size()>1)
        {
            //poping two persons as a pair
            int i=s.top();s.pop();
            int j=s.top();s.pop();
            
            //checking if i knows j
            if(mat[i][j]==0)
                s.push(i);
            else
                s.push(j);
        }
        
        // checking if the remaining one preson is the celebrity or not
        int celebrity=s.top();
        for(int i=0;i<n;i++)
        {
            if(i!=celebrity && (mat[celebrity][i]==1 || mat[i][celebrity]==0))
                return -1;
        }
        
        return celebrity;    
    }
};