class Solution {
private:
    void sub(vector<int>& nums, set<vector<int>>& ans, vector<int> curr, int i, int n){
        if(i >= n){
            if(curr.size() > 1)
                ans.insert(curr);
            return ;
        }
        int x = curr.size();
        vector<int> arr;
        
        if(x == 0){
            sub(nums, ans, curr, i+1, n);
            curr.push_back(nums[i]);
            sub(nums, ans, curr, i+1, n);
        }
        
        else{
            sub(nums, ans, curr, i+1, n);
            if(curr[x-1] <= nums[i]){
                curr.push_back(nums[i]);
                sub(nums, ans, curr, i+1, n);
            }
            else{
                if(x > 1){
                    ans.insert(curr);
                }
                sub(nums, ans, {nums[i]}, i+1, n);
            }
        }
        
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        
        sub(nums, ans, {}, 0, nums.size());
        vector<vector<int>> arr;
        for(auto i:ans)
            arr.push_back(i);
        return arr;
    }
};