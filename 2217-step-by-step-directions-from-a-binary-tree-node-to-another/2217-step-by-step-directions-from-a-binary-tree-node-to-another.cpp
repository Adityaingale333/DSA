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
    // we can also do it without finding LCA 
    // we can get both the path rootToStart and rootToDest, till the LCA node both will have same path
    // we can remove the path till LCA and then do the same logic of converting remaining rootToStart into U + rootToDest 
    bool findPath(TreeNode* root, int target, string& path){
        if(root == NULL){
            return false;
        }

        if(root->val == target){
            return true;
        }

        path.push_back('L');
        if(findPath(root->left, target, path) == true){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(root->right, target, path) == true){
            return true;
        }
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToStart = "";
        findPath(root, startValue, rootToStart);

        string rootToDest = "";
        findPath(root, destValue, rootToDest);

        // we got rootToStart and rootToDest, now they both will have same path till LCA, we do not need to consider it

        int i = 0, j = 0;
        while(i < rootToStart.length() && j < rootToDest.length()){
            if(rootToStart[i] == rootToDest[j]){
                i++, j++;
            }
            else{
                break;
            }
        }

        // now after above loop we have our i and j pointer at the node after LCA

        string ans = "";

        while(i < rootToStart.length()){
            ans.push_back('U');
            i++;
        }

        while(j < rootToDest.length()){
            ans.push_back(rootToDest[j]);
            j++;
        }

        return ans;
    }
};