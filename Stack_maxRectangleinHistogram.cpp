class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int>s;

        //calculating the left smaller value for width
        for(int i=0;i<n;i++)
        {
            while(s.size()>0 && heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty())
                left[i]=-1;  //default left boundary
            else
                left[i]=s.top();
            s.push(i);
        }

        //removing extra element from the stack since we are using the same stack
        while(!s.empty())
            s.pop();

        //calculating the right smaller value for width
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()>0 && heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty())
                right[i]=n;  //default right boundary
            else
                right[i]=s.top();
            s.push(i);
        }

        int ans=0;
        //calculation of max rectangle area
        for(int i=0;i<n;i++)
        {
            int width=right[i]-left[i]-1;
            int currArea=heights[i] * width;
            ans=max(ans,currArea);
        }

        return ans;
    }   
};