/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if(!head)
                return head;
            ListNode* prevN = head;
            ListNode* nextN = head->next;
            head->next = NULL;
            while(nextN) {
                head = nextN;
                nextN = nextN->next;
                head->next = prevN;
                prevN = head;
            }
            return head;
        }
};

