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
    // iterative approach 
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){
            TreeNode* leftNode = q.front();
            q.pop();
            TreeNode* rightNode = q.front();
            q.pop();

            if(leftNode == NULL && rightNode == NULL) continue;

            if(leftNode == NULL || rightNode == NULL || leftNode->val != rightNode->val) return false;

            // we are checking adjacent elements in queue, so we need push carefully in queue
            // we need to compare left->left to right->right
            q.push(leftNode->left);
            q.push(rightNode->right);
            // and compare left->right to right->left
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        return true;
    }
};