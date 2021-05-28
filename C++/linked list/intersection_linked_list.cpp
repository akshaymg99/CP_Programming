#include <cstdlib>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        if (headA == headB)
            return headA;
        
        int L1 = 0, L2 = 0;
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        while (ptr1 != NULL) {
            ptr1 = ptr1 -> next;
            L1 ++;
        }
        while (ptr2 != NULL) {
            ptr2 = ptr2 -> next;
            L2 ++;
        }
        ptr1 = headA;
        ptr2 = headB;
        
        int diff = abs(L1 -L2);
        if (L1 > L2) {
            for(int i=0; i<diff; ++i) {
                ptr1 = ptr1 -> next;
            }
        }
        else if (L2 > L1) {
            for (int i=0; i<diff; ++i) {
                ptr2 = ptr2 -> next;
            }
        }
        
        while (ptr1 != NULL || ptr2 != NULL) {
            if (ptr1 == ptr2)
                return ptr1;
            
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        
        return NULL;
            
        
    }
    
};