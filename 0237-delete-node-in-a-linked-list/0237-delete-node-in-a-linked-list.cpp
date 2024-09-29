/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        // overwrite the value of node with value of next node
        node->val = node->next->val;

        // temp is next node
        ListNode* temp = node->next;

        // temp next is given to node next, to skip the node with same value
        node->next = temp->next;

        delete temp;






        /*if(head == NULL) return NULL;

        if(k == 1){
            Node* temp = head;
            head = head -> next;
            free(temp);
            return head;
        }

        int count = 0;
        Node* temp = head;
        Node* prev = NULL;

        while(temp != NULL){
            count++;
            if(count == node){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;  */  
    }
};