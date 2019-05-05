#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == NULL) {
            return head;
        }
        int len = k;
        ListNode *p = head, *q = head->next, *r = head;
        while (p && k) {
            k--;
            p = p->next;
        }
        if (k)  {
            return head;
        }
        r->next = reverseKGroup(p, len);
        while (q != p) {
            ListNode *tem = q->next;
            q->next = r;
            r = q;
            q = tem;
        }
        return r;
    }
};