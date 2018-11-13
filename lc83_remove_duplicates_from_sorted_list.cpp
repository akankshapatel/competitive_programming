/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        
        ListNode *prev, *curr;
        prev = head;
        curr = head->next;
        
        while(curr) {
            while(curr && prev->val == curr->val) // skip all duplicate values
                curr = curr->next;
            prev->next = curr;
            prev = curr;
            if(curr)  
                curr = curr->next;            
        }
        return head;        
    }
};
