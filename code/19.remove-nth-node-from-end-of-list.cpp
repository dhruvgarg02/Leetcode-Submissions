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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = new ListNode();
        p = head;
        int count = 0;
        while(p != NULL) {
            p = p->next;
            count++;
        }
        if (count == 1) return NULL;
        if (count == n) return head->next;
        p = head;
        while(p != NULL and count > n+1) {
            p = p->next;
            count--;
        }
        if(n == 1)
            p->next = NULL;
        else
            p->next = p->next->next;
        return head;
    }
};