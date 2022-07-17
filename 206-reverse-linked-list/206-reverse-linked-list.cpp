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
        if(head==NULL) return NULL;
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nex=curr->next;
       while(nex!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nex;
            nex=nex->next;
        }
        curr->next=prev;
        prev=curr;
        return prev;
    }
};