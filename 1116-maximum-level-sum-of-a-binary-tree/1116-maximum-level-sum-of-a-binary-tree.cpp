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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans = 0;
        int level = 0;

        queue<TreeNode*> q; // node 
        q.push(root);

        while(!q.empty()){
            level++;
            int sumAtCurrentLevel = 0;
            int n = q.size();

            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                sumAtCurrentLevel = sumAtCurrentLevel + node->val;

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }

            if(sumAtCurrentLevel > maxSum){
                maxSum = sumAtCurrentLevel;
                ans = level;
            }
            
        }
 
        return ans;
    }
};