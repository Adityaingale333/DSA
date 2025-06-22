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
    // we will do something similar to morris travesal
    // we need to point prev->right to curr->right
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        // Iterate over the tree starting from root
        while(curr != NULL){
            
            if(curr->left != NULL){
                // If there is a left subtree:
                // Find the rightmost node in that left subtree
                TreeNode* prev = curr->left;

                while(prev->right != NULL){
                    prev = prev->right;
                }
                
                // At this point, 'prev' is the rightmost node in left subtree
                // Connect it to the current node's right child
                prev->right = curr->right;

                // Move the entire left subtree to the right
                curr->right = curr->left;

                // Set the left child to NULL
                curr->left = NULL;
            }
            else{
                // Move to the next node in the list (which is now curr->right)
                curr = curr->right;
            }
        }
    }
};