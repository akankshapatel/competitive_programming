#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        /* checking NULL cases */
        
        if(!l1 && !l2)
            return l1;
        else if(!l1)
            return l2;
        else if (!l2)
            return l1;
        
        /* Initialization of extra variables */
        
        ListNode *copy_beg, *copy_end; // act as markers for list 1 to indicate node after which and node before which the nodes from list 2 have to be merged.
        ListNode *paste_beg, *paste_end; // act as markers for list 2 to indicate the first and the last node to be added in between copy_beg and copy_end in list 1
        ListNode *temp;
             
        copy_beg = copy_end = l1;
        paste_beg = paste_end = l2;
        
        while (copy_beg && paste_beg){
            
            /* Finding location to insert nodes in link1 */
            while(copy_beg->next && copy_beg->next->val < paste_beg->val) {
                copy_beg = copy_beg->next;
            }
            copy_end = copy_beg->next;
            
            /*if nodes of list 2 to be added after last node in list 1*/
            if(copy_end == NULL && copy_beg < paste_beg){
                copy_beg->next = paste_beg;
                return l1;    
            }
        
            /* Finding subpart of list 2 to be added in list 1 */
            while(paste_end->next && paste_end->next->val < copy_end->val){
                paste_end = paste_end->next;
            }
        
            /* if nodes of list 1 to be added after nodes of list 2 */
            if(paste_end->next == NULL && copy_beg->val > paste_end->val) {
                paste_end->next = copy_beg;
                copy_beg = paste_beg;
                l1=copy_beg;
                return l1;
            }
        
            /* else adding subpart of list 2 to list 1 */
            else {
                copy_beg->next = paste_beg;
                temp = paste_end->next;
                paste_end->next = copy_end;
                copy_beg = copy_end;
                paste_beg = paste_end = temp;
            }
        }
    return  l1;
        
    }
};

int main(){
	ListNode *l1;
	ListNode n11(-9);
	l1 = &n11;
	ListNode n12(3);
	n11.next = &n12;
	n12.next = NULL;
	
	ListNode *l2;
	ListNode n21(5);
	l2 = &n21;
	ListNode n22(7);
	n21.next = &n22;
	n22.next = NULL;
	
	Solution s;
	ListNode *mergedList = s.mergeTwoLists(l1, l2);
	while(mergedList){
	 	cout << mergedList->val <<" ";
		mergedList = mergedList->next;
	}
	
}
