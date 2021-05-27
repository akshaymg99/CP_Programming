#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct SinglyList {
    int val;
    SinglyList *next;
    SinglyList(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
    private:
        SinglyList *head;
    public:
        MyLinkedList() {
            head = NULL;
        }

        SinglyList* getnode(int index) {
            SinglyList* cur = head;
            for (int i=0; i<index && cur; ++i) {       
                cur = cur -> next;
            }   
            return cur;
        }
        SinglyList* getTail() {
            SinglyList* cur = head;
            while(cur && cur-> next) {
                cur = cur -> next;
            }
            return cur;
        }
        int get(int index) {
            SinglyList* cur = getnode(index);
            return cur == NULL ? -1 : cur->val;
        }
        void AddatHead(int val) {
            SinglyList* cur = new SinglyList(val);
            cur -> next = head;
            head = cur;
            return;
        }
        void AddatTail(int val) {
            if (head == NULL) {
                AddatHead(val);
                return;
            }
            SinglyList* prev = getTail();
            SinglyList* cur = new SinglyList(val);
            prev -> next = cur;
        }
        void AddatIndex(int index, int val) {
            if (index == 0) {
                AddatHead(val);
                return;
            }
            SinglyList* prev = getnode(index-1);
            if (prev == NULL) {
                return;
            }
            SinglyList* cur = new SinglyList(val);  
            SinglyList* next = prev -> next;
            cur -> next = next;
            prev -> next = cur;          
        }
        void deleteAtIndex(int index) {
            SinglyList* cur = getnode(index);
            if (cur == NULL) 
                return;
            SinglyList* prev = getnode(index-1);
            SinglyList* next = cur -> next;   
            if (prev) {
                prev -> next = next;
            }
            else {
                head = next;
            } 
        }
        void printList() {
            SinglyList* cur = head;
            while (cur) {
                cout << cur -> val;
                cur = cur -> next;
            }    
        }        
};

