/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> in;
    
    void dis(TreeNode* root){
        if(!root) return ;
        
        dis(root->left);
        in.push_back(root->val);
        dis(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        dis(root);
        
        sort(in.begin(), in.end());
        
        int ans = INT_MAX;
        
        for(int i= 1; i<in.size(); i++){
            ans = min(ans, (in[i] - in[i-1]));
        }
        
        return ans;
    }
};