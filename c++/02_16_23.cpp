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
int ans = 0;

class Solution {
public:
    int find(TreeNode* root, int h){
        if(root == nullptr) return h;
        return max(find(root->left, h+1), find(root->right, h+1));
    }
    
    int maxDepth(TreeNode* root) {
        return find(root, 0);
        
    }
};