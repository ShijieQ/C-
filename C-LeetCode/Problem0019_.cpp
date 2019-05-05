#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        p = head;
        int now = 1;
        if (n == len) {
            head = p->next;
        }
        else {
            while (now + n != len) {
                now++;
                p = p->next;
            }
            ListNode *q = p->next;
            p->next = q->next;
        }
        return head;
    }
};