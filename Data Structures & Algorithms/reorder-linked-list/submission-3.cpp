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
    void reorderList(ListNode* head) {
        if(!(head->next && head->next->next))return;
        int i =1;
        auto count =head;
        while(count->next) {
            i++;
            count = count->next;
        }

        auto split = head;
        for(int j=1; j <= i/2; j++){
            split = split->next;
        }

        auto head2 = reverseList(split);
        auto temp = head->next;
        auto temp2 = head2->next;

        while(temp && temp2){
            head->next = head2;
            head = temp;
            temp = head->next;

            head2->next = head;
            head2 = temp2;
            temp2 = head2->next;

        }
       // return head;
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
