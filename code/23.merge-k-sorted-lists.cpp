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
struct compare {
    bool operator()(ListNode* l, ListNode* r) {
        return l->val > r->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode*, vector<ListNode*>, compare> pq;
        
        for (auto i : lists) 
            if (i) pq.push(i);
        
        if (pq.empty()) return NULL;
        
        ListNode* head = pq.top();
        pq.pop();
        if (head -> next) pq.push(head -> next);
        
        ListNode* temp = head;
        
        while (!pq.empty()) {
            temp -> next = pq.top();
            pq.pop();
            temp = temp -> next;
            if (temp -> next) pq.push(temp -> next);
        }
        
        return head;
    }
};