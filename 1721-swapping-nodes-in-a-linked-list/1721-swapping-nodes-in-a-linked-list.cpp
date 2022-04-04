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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* a = nullptr;
        for (int i = 1; i <= k; i++) {
            a = fast;
            fast = fast->next; //k times
        }
        while (fast ) {
            fast = fast->next; //k+1 to n
            slow = slow->next; //n-k
        }
        swap(a->val,slow->val);
        return head;
    }
};