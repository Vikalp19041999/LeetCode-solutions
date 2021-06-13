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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* high = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* highHead = high;
        while(head != NULL) {
            if(head->val < x) {
                smallHead->next = head;
                smallHead = smallHead->next;
            } else {
                highHead->next = head;
                highHead = highHead->next;
            }
            head = head->next;
        }
        highHead->next = NULL;
        smallHead->next = high->next;
        return small->next;
    }
};