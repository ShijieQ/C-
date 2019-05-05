#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    struct cmp {
        bool operator()(const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int siz = lists.size();
        if (!siz) {
            return NULL;
        }
        priority_queue<ListNode *, vector<ListNode *>, cmp> que;
        for (int i = 0; i < siz; i++) {
            if (lists[i]) {
                que.push(lists[i]);
            }
        }
        ListNode *ans = new ListNode(-1);
        ListNode *r = ans;
        while (!que.empty()) {
            r->next = que.top();
            que.pop();
            r = r->next;
            if (r->next) {
                que.push(r->next);
            }
        }
        return ans->next;
    }
};