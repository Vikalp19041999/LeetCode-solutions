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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) {
            return head;
        }
        int count = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *curr = dummy;
        ListNode *nex = dummy;
        while(curr->next != NULL) {
            curr = curr->next;
            count = count + 1;
        }
        while(count >= k) {
            curr = pre->next;
            nex = curr->next;
            for(int i=1; i<k; i++) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            count = count - k;
        }
        return dummy->next;
    }
};