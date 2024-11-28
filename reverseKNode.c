/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *new_head = head, *p = head, *last_p = NULL;
    while (p != NULL) {
        struct ListNode* tail = p;
        bool flag = false;
        for (int i = 0; i < k - 1; i++) {
            if (tail) tail = tail->next;
            else {
                flag = true;
                break;
            }
        }
        if (flag || (tail == NULL)) break;
        struct ListNode* tmp1 = p, *tmp2 = p->next;
        for (int i = 0; i < k - 1; i++) {
            struct ListNode* tmpp = tmp2->next;
            tmp2->next = tmp1;
            tmp1 = tmp2;
            tmp2 = tmpp;
        }
        if (last_p == NULL) new_head = tail;
        else last_p->next = tail;
        p->next = tmp2;
        last_p = p;
        p = tmp2;
    }
    return new_head;
}