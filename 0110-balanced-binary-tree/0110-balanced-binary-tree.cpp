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
// so this height function which we generally use to find depth of the tree
// we tweak it a little bit, and use it to return -1 if tree is not balanced
// while calculating lh and rh of every node, we check if their abs diff is more than 1 or not
// if more than 1, then we return -1
// and also to exit early if any of the lh or rh comes to be -1, we return -1
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int lh = height(root->left);
        if(lh == -1){
            return -1;
        } 
        int rh = height(root->right);
        if(rh == -1){
            return -1; 
        } 
        
        if(abs(lh - rh) > 1){
            return -1;
        }

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};