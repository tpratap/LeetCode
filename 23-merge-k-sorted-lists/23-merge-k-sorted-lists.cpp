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
        ListNode *temp; 
        ListNode *newNode = new ListNode;
        newNode->next = NULL; 
        temp = newNode;

        while (head1!=NULL && head2!=NULL) {
            if (head1->val <= head2->val) {
                temp->next = head1; 
                temp = temp->next;
                head1 =head1->next;
            }
            else {
                temp->next = head2;
                temp=temp->next;
                head2 = head2->next;
            }
        }
        if(head1!=NULL)
            temp->next = head1;
        else
            temp->next = head2;
        
        temp = newNode->next;
        delete(newNode);
        return temp;
    }
    
    ListNode* MergeSort(vector<ListNode*>& Lists, int start, int end)
    {
        if (start == end)
        {
            return Lists[start];
        }
        
        if (start > end)
        {
            return NULL;
        }
        
        int mid = (start + end) / 2;
        ListNode* left = MergeSort(Lists, start, mid);
        ListNode* right = MergeSort(Lists, mid + 1, end);
        
        ListNode* head = mergeTwoLists(left, right);
        
        return head;
    }
       
    ListNode* mergeKLists(vector<ListNode*>& Lists) {
        int n = Lists.size();
        
        return MergeSort(Lists,0, n-1);
    }
};