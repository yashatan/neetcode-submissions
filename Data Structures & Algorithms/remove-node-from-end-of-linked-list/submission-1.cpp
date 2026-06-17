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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto temp = head;
        int length = 1;
        while(temp->next){
            temp = temp->next;
            length++;
        }

        n = length - n;
        temp = head;

        if (n ==0){
            if(temp->next){
                head = head->next;
            }else{
                head = nullptr;
            }
            return head;
        }

        while(n>1){
            temp = temp->next; 
            n--;
        }

        
        temp->next = temp->next->next;

        return head;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* newHead = head;
        if (head->next){
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;
        return newHead;
    }
};
