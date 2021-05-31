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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *p1 = head, *p2 = head;
        while(p2 != NULL && p2->next != NULL) {
            p2 = p2->next->next;
            p1 = p1->next;
        }
        return p1;
    }
};