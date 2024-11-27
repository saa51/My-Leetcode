/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <queue>
#include <stdlib.h>
using namespace std;

typedef struct kvpair {
    int key;
    ListNode* next;
}kvpair;

typedef struct compare {
    bool operator()(const kvpair& lhs, const kvpair& rhs) const {
        return lhs.key > rhs.key;
    }
}compare;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<kvpair, vector<kvpair>, compare> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                kvpair p = {lists[i]->val, lists[i]->next};
                pq.push(p);
            }
        }
        ListNode* res = NULL, *current = NULL;
        while (!pq.empty()) {
            kvpair p = pq.top();
            pq.pop();
            if (res == NULL) 
                current = res = new ListNode(p.key);
            else {
                current->next = new ListNode(p.key);
                current = current->next;
            }
            if (p.next != NULL) {
                kvpair next_p = {p.next->val, p.next->next};
                pq.push(next_p);
            }
        }
        return res;
    }
};