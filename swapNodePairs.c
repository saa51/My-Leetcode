/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *new_head = head, *p = head, *last_p = NULL;
    while (p != NULL && p->next != NULL) {
        struct ListNode* tmp = p->next;
        p->next = tmp->next;
        tmp->next = p;
        if (last_p == NULL) new_head = tmp;
        else last_p->next = tmp;
        last_p = p;
        p = p->next;
    }
    return new_head;
}
