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
    // MORRIS INORDER TRAVERSAL 
    // we will make temporary threads from "root ke left subtree ka rightmost node se root tak"
    // jisse hum bina backtracking use kre vapas root node pr jaa ske 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){ // agar left hai hi nahi to chup chap root print krkr right chale jao
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{ // agar left hai toh......
                TreeNode* prev = curr->left; // ek prev node lo usko left subtree ke rightmost node tak bhejo
                while(prev->right != NULL && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == NULL){ // agar wo rightmost null ko point kr raha hai mtlb pehli baar aaye hai
                    prev->right = curr;// isliye usko root ki taraf point krdo
                    curr = curr->left;// ab hamare pass rightmost aur root ka connection hai toh ab aur left traverse karo
                }

                else{ // agar vo pehle se root ko point kr rha hai mtlb hum pehle bhi aa chuke hai
                    prev->right = NULL; // isliye usko null point krke connection break kro
                    ans.push_back(curr->val); // hume pura left traverse kr liya mtlb ab ye root hai, to apna ans me le liya
                    curr = curr->right; // ab right traverse kro, mtlb fir se left subtree ka rightmost.............
                }
            }
        }
        return ans;
    }
};