class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int rounds = 0;
        
        sort(tasks.begin(), tasks.end());
        
        int n = tasks.size();
        if(n <= 1) return -1;
        
        int i = 1;
        while(i < n){
            int cnt;
            if(tasks[i] == tasks[i-1]) cnt = 2;
            else return -1;
            
            i++;
            
            while(i < n && tasks[i] == tasks[i-1]){
                cnt++;
                i++;
            }
            
            rounds += cnt/3;
            
            if(cnt%3 != 0) rounds++;
            i++;
        }
        
        if(tasks[n-1] != tasks[n-2]) return -1;
        
        return rounds;
    }
};