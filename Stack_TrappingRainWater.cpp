//Brute Force       TC:O(n^2)       SC:O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        int waterquantity=0;
        int n=height.size();
        

        //find the leftmax limit and the rightmax limit for each height
        for(int i=0;i<n;i++)
        {
            int leftmax=0;
            //finding the leftmax bar limit
            for(int j=0;j<=i;j++)
            {
                leftmax=max(height[j],leftmax);
            }

            int rightmax=0;
            //finding the rightmax bar limit
            for(int j=i;j<n;j++)
            {
                rightmax=max(height[j],rightmax);
            }

            waterquantity += max(0, min(leftmax, rightmax) - height[i]);

        }

        return waterquantity;
    }
};


//Optimised using prefix Array method.     TC:O(n)  and SC:O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        //arrays for storing values for each bar
        vector<int> rightmax(n,0);
        vector<int> leftmax(n,0);

        leftmax[0]=height[0];
        rightmax[n-1]=height[n-1];

        //finding the leftmax bar limit
        for(int i=1;i<n;i++)
        leftmax[i]=max(height[i],leftmax[i-1]);
        
        //finding the rightamx bar limit
        for(int i=n-2;i>=0;i--)
            rightmax[i]=max(height[i],rightmax[i+1]);
        
            // calculating the final answer
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=min(leftmax[i],rightmax[i])-height[i];

        return ans;
    }
};


//Two Pointer Approach.     TC:O(n)  SC:O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        //two pointers
        int l=0;
        int r=n-1;
        int lmax=-1;
        int rmax=-1;
        int ans=0;

        while(l<r)
        {
            //maximum element from the left side
            lmax=max(height[l],lmax);

            //maximum element from the right side
            rmax=max(height[r],rmax);

            //calculating the answer
            if(lmax<rmax)   //water storage is dependent upon lmax
            {
                ans+=lmax-height[l];
                l++;
            }
            else   //water storage is dependent upon rmax
            {
                ans+=rmax-height[r];
                r--;
            }
        }

        return ans;
    }
};