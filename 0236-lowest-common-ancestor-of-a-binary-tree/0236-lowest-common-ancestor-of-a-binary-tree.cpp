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
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return NULL;
        }

        if(root == p || root == q){
            return root;
        }

        TreeNode* leftLCA = findLCA(root->left, p, q);
        TreeNode* rightLCA = findLCA(root->right, p, q);

        if(leftLCA && rightLCA){
            return root;
        }
        else if(leftLCA != NULL){// leftLCA is not null means rightLCA is null, 
            return leftLCA; // so we return leftLCA
        }
        else{ // either rightLCA is not null so we return rightLCA, 
            return rightLCA;// if both null, then we return rightLCA as bot left and right are NULL
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p, q);
    }
};