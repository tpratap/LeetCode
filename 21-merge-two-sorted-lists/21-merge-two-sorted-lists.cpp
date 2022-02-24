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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* temp;
        ListNode* head;
        
        if(head1 == NULL && head2 == NULL)
            return NULL;
        
        if(!head1)
            return head2;
        
        if(!head2)
            return head1;
        
        if(head1->val < head2->val) {
            head = head1;
            head1  = head1->next;
        }
        else {
            head = head2;
            head2  = head2->next;
        }
        
        temp = head;
        
        while(head1 && head2) {
            if(head1->val < head2->val) {
                temp->next = head1;
                head1  = head1->next;
            }
            else {
                temp->next = head2;
                head2  = head2->next;
            }
            temp = temp->next;
        }
            
        if(!head2) {
            temp->next = head1;
        }
        
        if(!head1) {
            temp->next = head2;
        }
        
        return head;
    }
};