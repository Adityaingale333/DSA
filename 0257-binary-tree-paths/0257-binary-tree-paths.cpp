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
    void solve(TreeNode* root, string temp, vector<string>& ans){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(temp);
            return;
        }

        if(root->left){
            solve(root->left, temp + "->" + to_string(root->left->val), ans);
        }

        if(root->right){
            solve(root->right, temp + "->" + to_string(root->right->val), ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = to_string(root->val);
        solve(root, temp, ans);
        return ans;
    }
};