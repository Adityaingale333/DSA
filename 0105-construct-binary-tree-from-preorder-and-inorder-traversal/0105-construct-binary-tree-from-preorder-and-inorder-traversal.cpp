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
    TreeNode* solve(int start, int end, vector<int>& preorder, vector<int>& inorder, int& idx){
        if(start > end){
            return NULL;
        }

        int nodeVal = preorder[idx];
        idx++;

        int i = start ;
        for(; i<=end; i++){
            if(inorder[i] == nodeVal){
                break;
            }
        }

        TreeNode* node = new TreeNode(nodeVal);

        node->left = solve(start, i-1, preorder, inorder, idx);

        node->right = solve(i+1, end, preorder, inorder, idx);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = inorder.size();

        return solve(0, n-1, preorder, inorder, idx);
    }
};