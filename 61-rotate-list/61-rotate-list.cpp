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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        
        //Finding Length
        ListNode *cur = head;
        int len=1;
        while(cur->next){
            ++len;
            cur=cur->next;
        }
        
        //Now first we will make the LL circular by attaching the last node to head of LL
        //Then we will break the link list from len-k node
        
        cur->next=head;
        k=k%len;
        k=len-k;
        while(k--) cur = cur->next;
        
        head=cur->next;
        cur->next = NULL;
        
        return head;
    }
};