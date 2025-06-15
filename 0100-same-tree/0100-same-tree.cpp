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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que1;
        queue<TreeNode*> que2;

        que1.push(p);
        que2.push(q);

        while(!que1.empty() && !que2.empty()){
            TreeNode* node1 = que1.front(); 
            que1.pop();
            TreeNode* node2 = que2.front();
            que2.pop();

            if(node1 == NULL && node2 == NULL) continue;
            if(node1 == NULL || node2 == NULL) return false;
            if(node1->val != node2->val) return false;

            que1.push(node1->left);
            que1.push(node1->right);
            que2.push(node2->left);
            que2.push(node2->right);
        }

        return que1.empty() && que2.empty();
    }
};