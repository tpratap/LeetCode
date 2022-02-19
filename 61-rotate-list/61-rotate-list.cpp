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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode* curr = head;
        int n = 1;
        while(curr->next != NULL) {
            curr = curr->next;
            n++;
        }
        k %= n;
        curr->next = head;
        n = n-k;
        while(n--) {
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};