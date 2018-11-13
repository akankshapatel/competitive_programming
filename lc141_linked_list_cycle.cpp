#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
	public:
		bool hasCycle(ListNode *head) {
			if (!head)
				return false;
			if(head == head->next)
				return true;
			if(!head->next || !head->next->next)
				return false;
			ListNode *pos = head, *double_pos = head->next->next;

			while(double_pos){
				if(pos == double_pos)
					return true;
				pos = pos->next;
				if(!double_pos->next || !double_pos->next->next)
					return false;
				double_pos = double_pos->next->next;
			}
			return false;
		}
};

int main(){
	
	ListNode *head;
	ListNode n1(3);
	head = &n1;
	ListNode n2(2);
	n1.next = &n2;
	ListNode n3(0);
	n2.next = &n3;
	ListNode n4(2);
	n3.next = &n4;
	n4.next = &n2;

	Solution s;
	bool b =  s.hasCycle(head);
	if(b)
		cout <<"yes";
	else 
	cout <<"no";

	return 0;
}
