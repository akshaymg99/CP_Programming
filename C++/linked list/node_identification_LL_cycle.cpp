

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersection(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast)
                return slow;
        }
        return NULL;
    }
    
    ListNode* detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode* intersect = getIntersection(head);
        ListNode* ptr1 = head;
        
        if (intersect == NULL)
            return NULL;
        
        while (ptr1 != intersect) {
            ptr1 = ptr1 -> next;
            intersect = intersect -> next;
        }
        return ptr1;
    }
};