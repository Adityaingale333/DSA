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
    int solve(TreeNode* node, int& maxSum){
        if(node == NULL){
            return 0;
        }

        int l = solve(node->left, maxSum);
        int r = solve(node->right, maxSum);

        // case 1 : when we got the best answer from the below only
        int neeche_hi_milgaya_answer = l + r + node->val;

        //case 2 : when we good answer either from left or right
        int koi_ek_acha = node->val + max(l, r);

        // case 3 : when both left and right are bad, consider only root
        int only_root_acha = node->val;

        // we will take max of all the above 3 cases
        maxSum = max({maxSum, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});

        // we will only those cases where we an further explore, in case 1 we cannot explore further as we are
        // considering that we got the best answer below only, so we can only explore case2 and case3
        return max(koi_ek_acha, only_root_acha) ;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};