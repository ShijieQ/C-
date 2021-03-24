class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        ListNode *p = head, *q = head->next, *pre = nullptr;
        for (int i = 1; i < left; i++) {
            pre = p;
            p = p->next;
            q = q->next;
        }
        ListNode *tail = p;
        int len = right - left;
        for (int i = 0; i < len; i++) {
            ListNode *temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        tail->next = q;
        if (!pre) {
            return p;
        }
        pre->next = p;
        return head;
    }
};

class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next= head;
        ListNode *pre = dummy;
        for (int i = 1; i < left; i++) {
            pre = pre->next;
        }
        ListNode *curr = pre->next;
        for (int i = 0; i < right - left; i++) {
            ListNode *next = curr->next;
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy->next;
    }
};