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
    // if we observe, our path go in different direction from the LCA of both start and end node
    // so we can first find the LCA of start and end node
    // then we can go from LCA to start, store its path, then later convert it into U, bcz we will going up from start to LCA
    // then we can go from LCA to end, and append it to the ans
    TreeNode* findLCA(TreeNode* root, int p, int q){
        if(root == NULL || root->val == p || root->val == q){
            return root;
        }

        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);

        if(left && right){
            return root;
        }
        else if(left){
            return left;
        }
        else{
            return right;
        }
    }
    bool findPath(TreeNode* LCA, int target, string& path){
        if(LCA == NULL){
            return false;
        }

        if(LCA->val == target){
            return true;
        }

        path.push_back('L');
        if(findPath(LCA->left, target, path) == true){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(LCA->right, target, path) == true){
            return true;
        }
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = findLCA(root, startValue, destValue); //found LCA

        // next find path from lcaToStart and lcaToDest

        string lcaToStart = "";
        findPath(LCA, startValue, lcaToStart);

        string lcaToDest = "";
        findPath(LCA, destValue, lcaToDest);

        // we got lcaToStart, but we will be going from start to lca, so we need to convert all the characters into U

        string ans = "";

        for(int i=0; i<lcaToStart.length(); i++){
            ans.push_back('U');
        }

        return ans + lcaToDest;
    }
};