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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                result.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{ // if(prev->right = curr)
                    prev->right = NULL;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};