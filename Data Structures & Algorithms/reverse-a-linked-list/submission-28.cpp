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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        if ((cur == nullptr) || (cur->next == nullptr)){
            return cur;
        }else{
            ListNode* temp;
            ListNode* temp2;
            temp = cur->next;
            cur->next = nullptr;

            while(temp != nullptr){
                temp2 = temp->next;
                temp->next = cur;
                cur = temp;
                temp = temp2;
            }
        }
        return cur;
    }
};
