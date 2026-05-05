#include <bits/stdc++.h>

using namespace std;

/**
 * DEFINITION FOR SINGLY-LINKED LIST.
 * STRUCT LISTNODE {
 *     INT VAL;
 *     LISTNODE *NEXT;
 *     LISTNODE() : VAL(0), NEXT(NULLPTR) {}
 *     LISTNODE(INT X) : VAL(X), NEXT(NULLPTR) {}
 *     LISTNODE(INT X, LISTNODE *NEXT) : VAL(X), NEXT(NEXT) {}
 * };
 */


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //edge case
        if(!head || !head->next || k == 0) return head;

        //1 compare lenght and find the tail
        ListNode* tail = head;
        int n = 1;
        while(tail->next != null) {
            tail = tail->next;
            n++;
        }

        k = k % n;
        if(k == 0) return head;

        tail->next = head;
        ListNode* new_tail = head;
        for(int i = 0; i < n - k - 1; i++) {
            new_tail = new_tail->next;
        }

        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;

        return new_head;
    }
};