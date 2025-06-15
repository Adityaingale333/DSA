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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root); // considering root ko left to right dala hai
        // LR == 1 -> left to right dalo, LR == 0 -> right to left dalo
        bool LR = 1; // root ko Left to right daalna hai, isliye 1 kr rkha hai

        while(!q.empty()){
            int n = q.size();
            vector<int> level(n);
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();

                int index = (LR) ? i : n-i-1 ;
                level[index] = node->val;

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            ans.push_back(level);
            LR = !LR;
        }
        return ans;
    }
};