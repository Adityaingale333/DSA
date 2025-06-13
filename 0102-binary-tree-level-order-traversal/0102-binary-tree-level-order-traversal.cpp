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
    // BFS traversal on binary tree
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans; // if there is no root we return empty 

        queue<TreeNode*> q; // queue to store node, so we pop it it order and push it in level
        q.push(root); // initial root is pushed in queue

        while(!q.empty()){ // loop runs till queue is not empty
            int n = q.size(); // we need this n, bcz it means there are this much element on that level
            vector<int> level; // to store elements of a level
            for(int i=0; i<n; i++){
                TreeNode* node = q.front(); // pop the first element of the level
                q.pop();
                if(node->left != NULL) q.push(node->left); // if it has a left, push it in queue to maintain order in next level
                if(node->right != NULL) q.push(node->right);// if it has a right, push it in queue to maintain order in next level
                level.push_back(node->val); // push the node in level
            }
            ans.push_back(level); // push whole level in ans vector
        }
        return ans;
    }
};