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
    ListNode* middleNode(ListNode* head) {
        int num_items = 0;
        ListNode *slowPtr = head, *fastPtr = head;
        
        while(fastPtr != NULL) {
            num_items ++;
            
            if(num_items % 2 == 0){
                if(!slowPtr)
                    slowPtr = head;
                slowPtr = slowPtr->next;
            }
                
            fastPtr = fastPtr -> next;
        }
        
     return slowPtr;
    }
};
