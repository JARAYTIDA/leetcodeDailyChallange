class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> remArr(k,0);
        remArr[0]++;
        int currSum = 0;
        int rem = 0;
        int cnt = 0;
        for(auto i:nums){
            currSum += i;
            rem = (currSum%k + k)%k;
            cnt += remArr[rem];
            remArr[rem]++;
        }
        return cnt;
    }
};