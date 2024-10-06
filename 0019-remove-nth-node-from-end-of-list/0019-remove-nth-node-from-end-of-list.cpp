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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL && n==1){
            delete head;
            return NULL;
        } 

        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }

        int tempcount = count - n;

        if(tempcount == 0){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }

        temp = head;
        while(tempcount>1){
            temp = temp->next;
            tempcount--;
        }

        ListNode* front = temp->next;

        temp->next = front->next;

        delete front;

        return head;
    }
};