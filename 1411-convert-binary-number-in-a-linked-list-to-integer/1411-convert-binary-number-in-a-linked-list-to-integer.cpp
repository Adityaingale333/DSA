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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        vector<int> num;

        while(temp != NULL){
            num.push_back(temp->val);
            temp = temp->next;
        }

        int n = num.size();
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            if(num[i] == 1){
                //ans = ans + pow(2, n-i-1);
                ans = ans + (1 << n-i-1) ;
            }
            
        }

        return ans;
    }
};