class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0,totalCost=0;

        // for unique solution
        int start=0,currGas=0;

        for(int i=0;i<gas.size();i++)
        {
            // calculating total gas and cost
            totalGas+=gas[i];
            totalCost+=cost[i];
            currGas+=(gas[i]-cost[i]);

            // if currGas turns negative, increment i and startover
            if(currGas < 0)
            {
                start=i+1;
                currGas=0;
            }
        }

        // if totalGas<totalCost, we cannot complete the cyclic trip so, return -1
        return totalGas < totalCost ? -1 : start;
    }
};