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
    // the main issue we face in this problem is how to traverse backwards, means to parent side
    // so for that we will use a map and keep track of parents of each node

    void inorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        if(root == NULL){
            return;
        }

        if(root->left != NULL){ // before we go to root->left, store its parent in mao
            parent[root->left] = root;
        }
        inorder(root->left, parent);

        if(root->right != NULL){
            parent[root->right] = root;
        }
        inorder(root->right, parent);
    }

    void bfs(TreeNode* target, int k, unordered_map<TreeNode*, TreeNode*>& parent, vector<int>& ans){
        queue<TreeNode*> q; 
        q.push(target);

        unordered_set<int> visited; // bcz there will be cases where two child will try to push same parent twice
        visited.insert(target->val); // so to avoid that we use set

        int level = 0;
        while(!q.empty()){
            int n = q.size(); // so we can travel all elements of a particular level in one go

            if(level == k){ // we are at the required level, so break and print the answer
                break;
            }

            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                // go in all three possible direction and find the answer 
                // left
                if(curr->left != NULL && !visited.count(curr->left->val)){
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }

                // right
                if(curr->right != NULL && !visited.count(curr->right->val)){
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }

                // parent
                if(parent.count(curr) && !visited.count(parent[curr]->val)){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            level++;
        }

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent; // node -> node ka parent

        inorder(root, parent); // we will do dfs traversal in tree to populate the parent map

        // now that we have the ability to go in all directions from the target node, we will do a 
        // bfs traversal level wise and get all the nodes at k distance or k level from node

        vector<int> ans;

        bfs(target, k, parent, ans);

        return ans;
    }
};