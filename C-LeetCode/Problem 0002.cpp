#include<bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p, *q;
        p = l1, q = l2;
        int add = p->val + q->val;
        bool c = add/10;
        add = add%10;
        ListNode *ans = new ListNode(add);
        ListNode *l = ans;
        p = p->next, q = q->next;
        while (p || q) {
            if (p == NULL) {
                add = q->val + c;
                q = q->next;
            }
            else if (q == NULL) {
                add = p->val + c;
                p = p->next;    
            }
            else {
                add = p->val + q->val + c;
                q = q->next, p = p->next;
            }
            c = add/10;
            ListNode *tem = new ListNode(add%10);
            l->next = tem;
            l = l->next;
        }
        if (c) {
            ListNode *tem = new ListNode(1);
            l->next = tem;
        }
        return ans;
    }
};