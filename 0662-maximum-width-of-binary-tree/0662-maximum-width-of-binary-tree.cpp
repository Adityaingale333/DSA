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
/* The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes that would be present in a complete binary tree 
extending down to that level are also counted into the length calculation.*/

// this above para simply means that we have to assume the tree as a complete binary tree
// the only imp point to notice is we have to take care of end nodes, otherwise we could have directly return 2^n
// we can CBT indexing as, root(0) -> left(1), right(2) ==> i=0 -> 2*i+1 = 1, 2*1+2 = 2

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q; // node -> index
        q.push({root, 0});

        // to get width of any level we will need starting and end index of that level
        int maxWidth = 0;
        while(!q.empty()){
            unsigned long long startIdx = q.front().second; // <first node of a level, first index>
            unsigned long long endIdx = q.back().second; // <second node of a level, last index>
            maxWidth = max(maxWidth, (int)(endIdx - startIdx + 1));

            int n = q.size();

            for(int i=0; i<n; i++){ // we need first and last node of a level to find length, so we club all nodes of level together
                TreeNode* node = q.front().first; // node of level
                unsigned long long j = q.front().second; // index of that node, which we will use to give index to its child
                q.pop(); // karde bhai, nahi toh memory limit exceed de raha hai

                if(node->left != NULL) q.push({node->left, 2*j+1});// even if it is null then that index will be empty
                if(node->right != NULL) q.push({node->right, 2*j+2});
            }
        }
        return maxWidth;
    }
};