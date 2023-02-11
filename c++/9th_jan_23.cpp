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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        TreeNode* curr = root;
        TreeNode* pre;
        
        vector<int> ans;
        
        while(curr != nullptr){
            // ans.push_back(curr->val);
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            
            else{
                ans.push_back(curr->val);
                pre = curr->left;
                while(pre->right != curr && pre->right != nullptr)
                    pre = pre->right;
                
                if(pre->right == nullptr){
                    pre->right = curr;
                    curr = curr->left;
                }
                
                else if(pre->right == curr){
                    ans.pop_back();
                    pre->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        
        return ans;  
    }
};