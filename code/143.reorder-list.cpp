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
    void reorderList(ListNode* head) {
        if(head == NULL or head->next == NULL) return;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        
        // Finding Mid
        while(fast != NULL and fast->next != NULL) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // Breaking
        prev -> next = NULL;
        
        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);
        merge(l1, l2);
        
    }

private:
    ListNode* reverse(ListNode* head) {
        if (head == NULL or head -> next == NULL) return head;
        ListNode* p = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
    
    void merge(ListNode* l1, ListNode* l2) {
        while(l2 != NULL) {
            ListNode* next = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = next;
        }
    }
};