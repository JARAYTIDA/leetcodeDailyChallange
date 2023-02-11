class Solution {
private:
    vector<int> solve(vector<int>& ans, vector<vector<int>> adj, int node, int par, string &labels){
        vector<int> arr(26,0);
        arr[labels[node] - 'a']++;
        
        for(auto i:adj[node]){
            if(i != par){
                vector<int> temp = solve(ans, adj, i, node, labels);
                for(int i = 0; i<26; i++)
                    arr[i] += temp[i];
            }
        }
        
        ans[node] = arr[labels[node]-'a'];
        
        return arr;
        
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> ans(n);
        solve(ans, adj, 0, -1, labels);
        
        return ans;
        
    }
};