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
    // ROOT LEFT RIGHT
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL){
            return {};
        }

        vector<int> ans;

        stack<TreeNode*> st;
        st.push(root); // initial root is pushed in the stack

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val); // root value is printed, and then we go for left and right
            // since we have to print left first and then right, but we are pushing nodes in a stack
            // so we will have to push right first and then left, bcz its LIFO
            if(node->right != NULL) st.push(node->right);
            if(node->left != NULL) st.push(node->left);
        }
        return ans;
    }
};