#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;
        ListNode *ans = new ListNode(-1);
        ListNode *r = ans;
        while (p && q) {
            if (p->val < q->val) {
                r->next = p;
                p = p->next;
            }
            else {
                r->next = q;
                q = q->next;
            }
            r = r->next;
        }
        if (p) {
            r->next = p;
        }
        else {
            r->next = q;
        }
        r = ans->next;
        delete ans;
        return r;
    }
};