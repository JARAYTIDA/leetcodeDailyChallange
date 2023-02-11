class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_g = 0;
        int curr_c = 0;
        int n = cost.size();
        
        for(int i = 0; i<n; i++){
            curr_g += gas[i];
            curr_c += cost[i];
        }
        if(curr_g < curr_c) return -1;
        
        int start = 0;
        int curr = 0;
        
        for(int i = 0; i<n; i++){
            curr += gas[i] - cost[i];
            if(curr < 0){
                start = i+1;
                curr = 0;
            }
        }
        return start;
    }
};