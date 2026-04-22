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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int length = lists.size();
        if (length ==0){
            return nullptr;
        }

        for( int i =0;i < length-1; i++){
            lists[i+1] = mergeLists(lists[i],lists[i+1]);
        }
        return lists[length-1];
    }

    ListNode* mergeLists(ListNode* head1, ListNode* head2){
        ListNode* result;
        ListNode* cur;

        if(head1 == nullptr){
            return head2;
        }

        if(head2 == nullptr){
            return head1;
        }
        if(head1->val < head2->val){
            result = cur = head1;
            head1 = head1->next;
        }else{
            result = cur = head2;
            head2 = head2->next;
        }

        while(head1 && head2){
            if(head1->val < head2->val){
                cur->next = head1;
                head1 = head1->next;
                cur = cur->next;
            }else{
                cur->next = head2;
                head2 = head2->next;
                cur = cur->next;
            }
        }

        if(head1){
            cur->next = head1;
        }

        if(head2){
            cur->next = head2;
        }
        return result;
    }
};
