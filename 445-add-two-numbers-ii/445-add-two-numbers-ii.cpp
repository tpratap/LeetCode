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
    ListNode* reverse(ListNode* head) {
        if(head->next == NULL || head == NULL)
            return head;
        
        ListNode* newHead = reverse(head->next);
        
        // a1 -> [a2 -> a3 -> a4 -> ]
        // After recursion
        // a1 -> [a2 <- a3 <- a4 <- ]
        // Our work is to reverse last part, make a2->next to be a1 and a1->next to NULL
        // a1 = head, a2 = head->next make a2->next = a1;
        
        head->next->next = head;
        //Now make the head(a1) next to be NULL
        head->next = NULL;
        return newHead;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = reverse(l1); 
        ListNode* head2 = reverse(l2);
        
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        
        int carry = 0;
        while(head1 && head2) {
            int sum = head1->val + head2->val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* temp = new ListNode(sum);
            dummy->next = temp;
            dummy = dummy->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        
        while(head1) {
            int sum = head1->val+ carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* temp = new ListNode(sum);
            dummy->next = temp;
            dummy = dummy->next;
            head1 = head1->next;
        }
        
        while(head2) {
            int sum = head2->val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* temp = new ListNode(sum);
            dummy->next = temp;
            dummy = dummy->next;
            head2 = head2->next;
        }
        
        if(carry != 0) {
            ListNode* temp = new ListNode(carry);
            dummy->next = temp;
        }
        
        head = reverse(head->next);
        
        return head;
    }
};