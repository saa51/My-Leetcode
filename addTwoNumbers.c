/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode* startNode = NULL;
    struct ListNode* lastNode = NULL;
    while (l1 != NULL && l2!= NULL) {
        struct ListNode* currentNode = malloc(sizeof(struct ListNode));
        if (lastNode != NULL) lastNode->next = currentNode;
        else startNode = currentNode;
        currentNode->val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        lastNode = currentNode;
        l1 = l1->next;
        l2 = l2->next;
    }
    struct ListNode* remain = (l1 != NULL) ? l1 : l2;
    while (remain != NULL) {
        struct ListNode* currentNode = malloc(sizeof(struct ListNode));
        lastNode->next = currentNode;
        currentNode->val = (remain->val + carry) % 10;
        carry = (remain->val + carry) / 10;
        lastNode = currentNode;
        remain = remain->next;
    }
    if (carry == 1) {
        struct ListNode* currentNode = malloc(sizeof(struct ListNode));
        lastNode->next = currentNode;
        currentNode->val = carry;
        lastNode = currentNode;
    }
    lastNode->next = NULL;
    return startNode;
}
