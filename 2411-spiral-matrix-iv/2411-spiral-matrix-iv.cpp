/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int id = 0;
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;

        while(top<=down && left<=right){
            //left to right
            if(id == 0){ 
                for(int i=left; i<=right && head != NULL ; i++){
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }
            // top to down
            if(id == 1){
                for(int i=top; i<=down && head != NULL ; i++){
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }
            // right to left
            if(id == 2){
                for(int i=right; i>=left && head != NULL ; i--){
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }
            // down to top
            if(id == 3){
                for(int i=down; i>=top && head != NULL ; i--){
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
            id = (id+1)%4;
        }
        return matrix;
    }
};