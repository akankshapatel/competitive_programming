#include<iostream>

/* Assuming following declaration based on errors in leetcode and comments of other questions
   struct ListNode{
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
   };
*/

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
    ListNode *head;
    ListNode *tail;
    public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = tail = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index == 0){
            if(!head)
                return -1;
            return head->val;
        }
        ListNode *curr = head;
        int pos = 0;
        while(pos!=index && curr){
            curr = curr->next;
            pos++;
        }
        if(!curr)
            return -1;
        return curr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *n = new ListNode(val);
        n->next = head;
        head = n;
        if(tail == NULL)
            tail = n;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *n = new ListNode(val);
        n->next = NULL;
        if(tail == NULL){
            head = tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
        }
        ListNode *curr = head;
        int pos = 0;
        while(pos!=index-1 && curr){
            curr = curr->next;
            pos++;
        }
        if(!curr)
            return;
        ListNode *n = new ListNode(val);
        n->next = curr->next;
        if(tail == curr)
            tail = n;
        curr->next = n;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index == 0) {
            if(head){
                ListNode *delNode = head;
                if(head == tail) // single element
                    tail = NULL; 
                head = head->next; 
                delete delNode;
            }
            return;
        }
        ListNode *curr = head;
        int pos = 0;
        while(pos != index-1 && curr){
            curr = curr->next;
            pos++;
        }
        if(!curr || !(curr->next))
            return;
        ListNode *delNode = curr->next;
        if(!curr->next->next) // deleting tail
            tail = curr;
        curr->next = curr->next->next;
        delete delNode;
    }

    /* made to assist coding */
    void printList(){
        ListNode *curr = head;
        cout<<"head = " << head->val << "tail = " << tail->val <<"\n";
        while(curr){
            cout<< curr->val << "\t";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main(){
    MyLinkedList obj;
    obj.addAtHead(7);
    obj.printList();
    obj.addAtHead(2);
    obj.printList();
    obj.addAtHead(1);
    obj.printList();
    obj.addAtIndex(3,0);
    obj.printList();
    obj.deleteAtIndex(2);
    obj.printList();
    obj.addAtHead(6);
    obj.printList();
    obj.addAtTail(4);
    obj.printList();
    cout<< obj.get(4) << endl;
    obj.printList();
    obj.addAtHead(4);
    obj.printList();
    obj.addAtIndex(5,0);
    obj.printList();
    obj.addAtTail(6);
    obj.printList();
    return 0;   
}
