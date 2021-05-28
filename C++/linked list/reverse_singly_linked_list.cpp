
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp -> next;
            size ++;
        }
        if (size == 0)
            return NULL;
        if (size == 1) 
            return head;
        
        if (size == 2) {
            ListNode* prev = head;
            ListNode* cur = head ->next;  
            cur -> next = prev;
            prev -> next = NULL;
            head = cur;
            return head;
        }
        else if (size >= 3) {
            ListNode* prev = head;
            ListNode* cur = prev -> next;
            ListNode* fut = cur -> next;  
            prev -> next = NULL;
            
            while (fut != NULL) {
                if (prev == cur)
                    break;
                
                cur -> next = prev;
                prev = cur;
                cur = fut;
                
                if (fut -> next)
                    fut = fut -> next;
                else 
                    head = fut;
            }
           
        }
         return head;
        
    }
};


/* Recursive solution

class Solution { 
public:
    ListNode* recursiveList (ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* p = recursiveList(head->next);
        head -> next -> next = head;
        head -> next = NULL;

        return p;
    }
} 

*/