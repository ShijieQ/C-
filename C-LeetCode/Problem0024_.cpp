#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *tem = new ListNode(-1);
        tem->next = head;
        ListNode *p = tem;
        while (p->next) {
            if (p->next->next == NULL) {
                break;
            }
            ListNode *q = p->next->next->next;
            ListNode *r = p->next;
            p->next = p->next->next;
            p->next->next = r;
            p->next->next->next = q;
            p = p->next->next;
        }
        return tem->next;
    }
};