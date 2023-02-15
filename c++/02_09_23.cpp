class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        
        vector<unordered_map<string,int>> arr(26);
        // int n = ideas.size();
        
        for(int i = 0; i<n; i++){
            char ch =  ideas[i][0];
            string str = ideas[i].substr(1);
            
            arr[ch-'a'][str] ++;
        }
        long long ans = 0;
        
        for(int i = 0; i<25; i++){
            for(int j = i+1; j<26; j++){
                int cnt = 0;
                for(auto k:arr[i])
                    if(arr[j].find(k.first) != arr[j].end())
                        cnt++;
                
                ans += 2LL*(arr[i].size() - cnt)*(arr[j].size() - cnt);
            }
        }
        
        
        return ans;
    }
};