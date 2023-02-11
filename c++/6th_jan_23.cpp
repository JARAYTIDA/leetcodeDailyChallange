class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int m = *max_element(costs.begin(), costs.end());
        vector<int> cost_freq(m+1);
        int count = 0;
        
        for(auto i:costs)
            cost_freq[i]++;
        
        for(int i = 0; i<=m; i++){
            if(cost_freq[i] == 0)
                continue;
            else if(coins < 0)
                break;
            else {
                int cost = min(cost_freq[i], coins/i);
                coins -= i*cost;
                if(coins >= 0)
                    count += cost;
            }
        }
        
        return count;
    }
};