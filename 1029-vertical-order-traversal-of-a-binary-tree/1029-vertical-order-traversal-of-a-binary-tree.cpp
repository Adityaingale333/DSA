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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // multiset also stores duplicate values, that too in sorted order 
        map<int, map<int, multiset<int>>> mp; // column -> level -> {elements of column}

        queue<pair<TreeNode*, pair<int,int>>> q; // node-> {column, level}
        q.push({root, {0,0}});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int column = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            mp[column][level].insert(node->val);

            if(node->left != NULL) q.push({node->left, {column-1, level+1}});
            if(node->right != NULL) q.push({node->right, {column+1, level+1}});
        }

        vector<vector<int>> ans;
        for(auto& [col, levels] : mp){
            vector<int> temp;
            for(auto& [lvl, nodes] : levels){
                temp.insert(temp.end(), nodes.begin(), nodes.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};