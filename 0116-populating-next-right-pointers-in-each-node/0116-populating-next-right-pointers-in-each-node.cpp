/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // time = O(n)
    // space = O(n) for queue, O(n/2) in worst case of the vector
    Node* connect(Node* root) {
        if(root == NULL) return root;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<Node*> levelNodes;

            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();

                levelNodes.push_back(node);

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }

            for(int i=0; i<levelNodes.size()-1; i++){
                levelNodes[i]->next = levelNodes[i+1];
            }
            levelNodes.back()->next = NULL;
        }

        return root;
    }
};