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
    TreeNode* solve(TreeNode* root){
        if(root == NULL){
            return NULL;
        }

        TreeNode* node = new TreeNode(root->val);
        node->left = solve(root->right);
        node->right = solve(root->left);
        return node;
    }
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};