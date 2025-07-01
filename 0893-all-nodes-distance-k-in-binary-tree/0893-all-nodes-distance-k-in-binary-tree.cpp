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
    void preorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        if(root == NULL){
            return;
        }

        if(root->left != NULL){
            parent[root->left] = root;
        }
        preorder(root->left, parent);

        if(root->right != NULL){
           parent[root->right] = root;
        }
        preorder(root->right, parent);
    }

    void bfs(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parent, vector<int>& ans, int k){
        queue<TreeNode*> q; // node 
        q.push(target);

        unordered_set<int> visited; // two child will have same parent
        visited.insert(target->val);

        while(!q.empty()){
            int n = q.size();
        
            if(k == 0){
                break;
            }

            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL && !visited.count(node->left->val)){
                    visited.insert(node->left->val);
                    q.push(node->left);
                }

                if(node->right != NULL && !visited.count(node->right->val)){
                    visited.insert(node->right->val);
                    q.push(node->right);
                }

                if(parent.count(node) && !visited.count(parent[node]->val)){
                    visited.insert(parent[node]->val);
                    q.push(parent[node]);
                }
            }

            k--;
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent; // bcz we will have to traverse through parent also

        preorder(root, parent); // populate parent map

        vector<int> ans;

        bfs(root, target, parent, ans, k); // do bfs traversal, and get nodes at level k from target

        return ans;
    }
};