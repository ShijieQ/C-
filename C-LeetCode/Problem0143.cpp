class Solution {
public:
    ListNode* getMiddleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *ans = slow->next;
        slow->next = nullptr;
        return ans;
    }

    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *p = head, *q = head->next;
        p->next = nullptr;
        while (q != nullptr) {
            ListNode *r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }

    void insert(ListNode* l, ListNode* r) {
        while (r != nullptr) {
            ListNode* k = l->next;
            l->next = r;
            ListNode* temp = r->next;
            r->next = k;
            l = k;
            r = temp;
        }
    }

    void reorderList(ListNode* head) {
        insert(head, reverse(getMiddleNode(head)));
    }
};