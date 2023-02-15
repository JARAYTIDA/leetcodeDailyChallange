class Solution {
public:
    int ans = INT_MIN;
    
    int dfs(vector<vector<int>> &adj, string &s, int node, int par){
        int a1 = INT_MIN, a2 = INT_MIN;
        for(auto i:adj[node]){
            if(i != par){
                int temp = dfs(adj, s, i, node);
                if(s[i] == s[node]) temp = 0;
                if(temp < a1 && temp >= a2){
                    a2 = temp;
                }
                
                else if(temp >= a1){
                    a2 = a1;
                    a1 = temp;
                }
                
                
                // if(s[i] == s[node])
                //     count = max(count, 1);
                // else count = max(count, temp+1);
                
                
            }
        }
        if(a2 == INT_MIN){
            if(a1 == INT_MIN)
                ans = max(ans, 1);
            else ans = max(ans, a1 + 1);
        }
        else ans = max(ans, a1 + a2 + 1);

        return (a1 == INT_MIN && a2 == INT_MIN) ? 1 : max(a1+1, a2+1);
    }
    
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(parent.size());
        
        for(int i = 0; i<n; i++){
            if(parent[i] == -1) continue;
            
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        
        dfs(adj, s, 0, -1);
        
        return ans;
        
    }
};