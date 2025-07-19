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
    // we can perform simple BFS on the tree and find the time to reach last level
    // but for that we will need to traverse in the parent direction also, so we will convert it into the graph
    void preorderForParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        if(root == NULL){
            return;
        }

        if(root->left != NULL){
            parent[root->left] = root;
        }

        preorderForParent(root->left, parent);

        if(root->right != NULL){
            parent[root->right] = root;
        }

        preorderForParent(root->right, parent);
    }
    TreeNode* dfs(TreeNode* root, int& start){
        if(root == NULL || root->val == start){
            return root;
        }

        TreeNode* left = dfs(root->left, start);
        if(left) return left;

        return dfs(root->right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;

        preorderForParent(root, parent); // populate parent map

        TreeNode* startNode = root->val == start ? root : dfs(root, start); // get the starting node

        queue<pair<TreeNode*, int>> q; // node, time
        q.push({startNode, 0}); 

        unordered_set<int> visited;
        visited.insert(startNode->val);

        int ans = 0;
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int time = q.front().second;
            q.pop();

            ans = time;

            if(node->left != NULL && !visited.count(node->left->val)){
                visited.insert(node->left->val);
                q.push({node->left, time+1});
            }

            if(node->right != NULL && !visited.count(node->right->val)){
                visited.insert(node->right->val);
                q.push({node->right, time+1});
            }

            if(parent[node] != NULL && !visited.count(parent[node]->val)){
                visited.insert(parent[node]->val);
                q.push({parent[node], time+1});
            }
        }

        return ans;
    }
};