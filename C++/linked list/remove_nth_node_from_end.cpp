
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = 0;
        ListNode* cur = head;
        while (cur != NULL) {
            cur = cur -> next;
            N++;
        }
        int index = N - n;
        if (index < 0)
            return NULL;

        if (index == 0) {  // delete at head
            head = head -> next;
            return head;
        }
        
        cur = head;
        ListNode* prev = head;        
        for (int i=0; cur && i<index; ++i) {
            cur = cur -> next;
        }
        for (int i=0; prev && i<index-1; ++i) {
            prev = prev -> next;
        }
        
        prev -> next = cur -> next;
        return head;
    }
};

/* another approach (one-pass)

def removeNthFromEnd(self, head, n):
        size = 1
        cur = p = head
        while cur.next:
            size += 1
            cur = cur.next
            if size > n + 1:
                p = p.next
        if size == n:
            return head.next
        else:
            p.next = p.next.next
            return head
*/
