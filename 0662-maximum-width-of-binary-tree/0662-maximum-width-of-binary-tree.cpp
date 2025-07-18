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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long maxWidth = 0;

        while(!q.empty()){
            unsigned long long start = q.front().second;
            unsigned long long end = q.back().second;

            maxWidth = max(maxWidth, end - start + 1);

            int n = q.size();

            for(int i=0; i<n; i++){
                TreeNode* node = q.front().first;
                unsigned long long idx = q.front().second;
                q.pop();

                if(node->left != NULL) q.push({node->left, (2*idx)+1});

                if(node->right != NULL) q.push({node->right, (2*idx)+2});
            }
        }

        return (int)maxWidth;
    }
};