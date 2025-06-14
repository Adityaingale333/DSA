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
// again here we are using the same height function with little more tweaks
// here at every node we are calculating the left path sum and right path sum, and we storing a max value
// max value, is compared at every node with, node->val + lh + rh, so to keep the highest sum a curve point brings
// to keep check of negative value, we take max of (0, lh), so as we take 0 always whenever there is -ve value
    int height(TreeNode* node, int& maxi){
        if(node == NULL){
            return 0;
        }

        int lh = max(0, height(node->left, maxi) );
        int rh = max(0, height(node->right, maxi) );

        maxi = max(maxi, lh + rh + node->val);

        return node->val + max(lh, rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        height(root, maxi);
        return maxi;
    }
};