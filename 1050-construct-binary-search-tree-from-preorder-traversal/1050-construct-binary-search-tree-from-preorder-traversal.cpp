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
    // we are given preorder of a BST, means we have all the nodes of BST
    // so if we sort them then we can get the inorder
    // and we can make a BST from preorder and inorder
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx){
        if(start > end){
            return NULL;
        }

        int rootVal = preorder[idx];
        idx++;
        int i = start;
        for(; i<=end; i++){
            if(inorder[i] == rootVal){
                break;
            }
        }

        TreeNode* node = new TreeNode(rootVal);
        node->left = solve(preorder, inorder, start, i-1, idx);
        node->right = solve(preorder, inorder, i+1, end, idx);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder;
        inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int idx = 0;
        return solve(preorder, inorder, 0, n-1, idx);
    }
};