tion for singly-linked list.
* struct ListNode {
	*     int val;
	*     ListNode *next;
	*     ListNode(int x) : val(x), next(NULL) {}
	* };
*/
class Solution {
	public:
		ListNode* removeElements(ListNode* head, int val) {
			if(!head)   // empty list
				return head;
			if(!head->next){    // single element in list
				if(head->val == val)
					return NULL;
				else
					return head;
			}

			while(head->val == val){ // eliminating initial elements with value 'val'
				if(head->next)
					head = head->next;
				else 
					return NULL;
			}       

			ListNode *curr = head->next;
			ListNode *prev = head;

			while(curr){
				while(curr && curr->val == val){
					curr = curr->next;
				}
				prev->next = curr;
				prev = curr;
				if(curr)
					curr = curr->next;
				else 
					break;
			}

			return head;
		}
};
