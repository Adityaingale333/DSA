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
    // to do it in O(n) time and O(1) space, we can check if the root of bst is in it's range or not  
    bool solve(TreeNode* root, long long min_of_range, long long max_of_range){
        if(root == NULL){
            return true;
        }

        if(root->val >= max_of_range || root->val <= min_of_range){
            return false;
        }

        bool left = solve(root->left, min_of_range, root->val);

        bool right = solve(root->right, root->val, max_of_range);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};