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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* resHead = new ListNode(head->val);
        ListNode* frontHead = resHead;
        head = head->next;
        int frontVal = resHead->val;
        
        while(head != nullptr)
        {
            
            // Element is greater than or equal to front of result list (Insert at front of result list)
            if(head->val >= frontVal)
            {
                frontHead->next = new ListNode(head->val);
                frontHead = frontHead->next;
                frontVal = frontHead->val;
            } else {
                ListNode* iter = resHead;
                while(iter != nullptr)
                {
                    // Element is less than result list head (Insert at the head of result List)
                    if(iter->val > head->val)
                    {
                        ListNode* tmp = resHead;
                        resHead = new ListNode(head->val, tmp);
                        break;
                    }
                    
                    // Find spot to insert
                    if(iter->val <= head->val && head->val <= iter->next->val)
                    {
                        ListNode* tmp = iter->next;
                        iter->next = new ListNode(head->val, tmp);
                        break;
                    }
                    iter = iter->next;
                }
            }
            head = head->next;
        }
        return resHead;
    }
};
