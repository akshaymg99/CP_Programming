/*
Problem link: https://leetcode.com/problems/rotate-list
Rotating a singly linked list
*/



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode* temp = head;
        int count = 0;
        while (temp -> next != NULL) {
            temp = temp -> next;
            count ++;
        }
        count ++;
        k = k % count;
        temp -> next = head;
        temp = head;
       
        for (int i=0; i<count-k-1; ++i) {
            temp = temp -> next;
        }
        ListNode* new_head = temp -> next;
        temp -> next = NULL;
        
        return new_head;
        
    }
};