/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // one way to do this is doing simple LCA on binary tree
    // time O(n)
    // recursion stack space O(h)
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p || root == q){
            return root;
        }

        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);

        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p, q);
    }
};