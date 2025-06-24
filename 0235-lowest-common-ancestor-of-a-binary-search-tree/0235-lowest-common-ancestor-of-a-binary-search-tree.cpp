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
    // as it is a BST, we can reduce the time to O(H)
    // LCA will be that root where both the p and q will be on its left and right, where it spilt
    // or if the root is one of p or q, the also we can say that both are not either one side 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        int curr = root->val;
        if(curr < p->val && curr < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        else if(curr > p->val && curr > q->val){
            return lowestCommonAncestor(root->left, p, q);
        } 
        
        return root;

    }
};