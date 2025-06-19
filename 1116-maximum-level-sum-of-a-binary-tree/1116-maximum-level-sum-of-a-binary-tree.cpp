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
    int maxLevelSum(TreeNode* root) {
        map<int, int> mp; // level -> sum of elements of that level
        queue<pair<TreeNode*, int>> q; // node -> level
        q.push({root, 1});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            int already_existing_level_value = mp[level];
            mp[level] = already_existing_level_value + node->val;

            if(node->left != NULL) q.push({node->left, level+1});
            if(node->right != NULL) q.push({node->right, level+1});
        }
 
        int ansLevel = -1;
        int maxSum = INT_MIN;
        for(auto& it : mp){
            if(it.second > maxSum){
                maxSum = it.second;
                ansLevel = it.first;
            }
        }
        return ansLevel;
    }
};