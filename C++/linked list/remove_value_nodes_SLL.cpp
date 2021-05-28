/*
Problem link: https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1207/
Remove linked list nodes containing given value
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;
        
        if (head -> next == NULL) {
            if (head -> val == val)
                return NULL;
        }
        ListNode* prev = head;
        while (prev -> val == val && head) {
            head = head -> next;
            prev = head;
            if (head == NULL)
                return NULL;
        }
        ListNode* cur = prev -> next;
        while (cur != NULL && prev!=NULL) {
            if (cur -> val == val) {
                prev -> next = cur -> next;
                cur = prev -> next;
                continue;
            }
            
            prev = prev -> next;
            if (cur)
                cur = cur -> next;
        }
        return head;   
        
    }
};