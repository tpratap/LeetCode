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
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        int carry = 0 ;
        while(l1 and l2){
            l1->val += l2->val +carry;
            carry = l1->val/10;
            l1->val %=10;
            dummy->next = l1;
            dummy = dummy->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            if(carry == 0){
                dummy->next = l1;
                break;
            }
            l1->val = l1->val +carry;
            carry = l1->val/10;
            l1->val %=10;
            dummy->next = l1;
            dummy = dummy->next;
            l1 = l1->next;      
        }
        while(l2){
            if(carry == 0){
                dummy->next = l2;
                break;
            }
            l2->val = l2->val +carry;
            carry = l2->val/10;
            l2->val %=10;
            dummy->next = l2;
            dummy = dummy->next;
            l2 = l2->next;      
        }
        if(carry !=0){
            dummy->next = new ListNode(carry);
        }
        dummy = head;
        head = head->next;
        dummy->next = NULL;
        delete(dummy);
        return head;
    }
};