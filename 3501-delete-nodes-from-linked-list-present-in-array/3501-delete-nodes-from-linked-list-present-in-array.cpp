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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toDelete(nums.begin(), nums.end());

        // Skip nodes to be deleted at the start
        while (head && toDelete.count(head->val)) {
            head = head->next;
        }

        ListNode* curr = head;
        while (curr && curr->next) {
            if (toDelete.count(curr->next->val)) {
                curr->next = curr->next->next; // unlink node only
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};