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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* evenhead=head->next;
        ListNode * op=head;
        ListNode * ep=head->next;
        while(op->next!=NULL && ep->next!=NULL)
        {
          op->next=op->next->next;
          ep->next=ep->next->next;
            op=op->next;
            ep=ep->next;
        } 
        op->next=evenhead;
        return head;
    }
};
