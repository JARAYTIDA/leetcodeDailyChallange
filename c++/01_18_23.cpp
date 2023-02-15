class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int mxSum = -30000, currMax = -30000, currMin = 30000, mnSum = 30000, total_sum = 0;
        
        for(auto i:nums){
            currMax = max(i, currMax + i);
            currMin = min(i, currMin + i);
            mxSum = max(mxSum, currMax);
            mnSum = min(mnSum, currMin);
            total_sum += i;
        }
        
        return mxSum > 0 ? max(mxSum, total_sum - mnSum) : mxSum;
        
    }
};