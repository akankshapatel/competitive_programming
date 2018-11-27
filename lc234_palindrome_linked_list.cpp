/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 **/
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if(head == NULL || head->next == NULL)
                return true;
            if(head->next->next == NULL){
                if(head->val == head->next->val)
                    return true;
                else
                    return false;
            }

            ListNode *pos, *next_pos, *double_pos, *old_pos;
            bool first_node = true;
            bool even;
            pos = head;
            next_pos = head->next;
            double_pos = head;

            while(double_pos){
                double_pos = double_pos->next->next;

                old_pos = pos;
                if(first_node){
                    old_pos->next = NULL;
                    first_node = false;
                }
                pos = next_pos;
                next_pos = next_pos->next;
                pos->next = old_pos;

                if(!double_pos->next) {
                    even = false;
                    break;
                }
                if(!double_pos->next->next){
                    even = true;
                    break;
                }
            }

            if(!even){
                pos = pos->next; 
            }
            while(next_pos){
                if(pos->val != next_pos->val)
                    return false;
                next_pos = next_pos->next;
                pos = pos->next;
            }
            return true;
        }
};
