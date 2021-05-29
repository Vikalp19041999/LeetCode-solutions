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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL,*tail=NULL;
        int carry=0;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        while(l1 && l2){
            int val=l1->val+l2->val+carry;
            carry=val/10;
            val=val%10;
            if(head==NULL)
                head=tail=new ListNode(val);
            else{
                tail->next=new ListNode(val);
                tail=tail->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1){
            int val=l1->val+carry;
            carry=val/10;
            val=val%10;
            tail->next=new ListNode(val);
            tail=tail->next;
            l1=l1->next;
        }
        while(l2){
            int val=l2->val+carry;
            carry=val/10;
            val=val%10;
            tail->next=new ListNode(val);
            tail=tail->next;
            l2=l2->next;
        }
        if(carry)
            tail->next=new ListNode(carry);
        
        return head;
    }
};