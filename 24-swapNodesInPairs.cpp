// Given a linked list, swap every two adjacent nodes and return its head. 
// You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

void recurse(ListNode* tmp)
{
    if(!tmp || !tmp->next || !tmp->next->next)
        return;

    ListNode* tmp2 = tmp->next;
    tmp->next = tmp2->next;
    tmp2->next = tmp2->next->next;
    tmp->next->next = tmp2;
    recurse(tmp->next->next);
}

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    recurse(dummy);
    return dummy->next;
}

void printList(ListNode* head)
{
    while(head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* itr = head;
    for(int i = 2; i < 10; i++)
    {
        itr->next = new ListNode(i);
        itr = itr->next;
    }
    printList( swapPairs(head) );
}