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
    
    ListNode* reverseLL(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nex;
        
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        curr=prev;
        return prev;
        
    }
    bool isPalindrome(ListNode* head) {
         if(head==NULL || head->next==NULL)  //means only one or 0 elements present
    {
        return true ;
    }
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
       
        
        fast=head;
        slow=reverseLL(slow);
        
        
         while(slow!=NULL)
        {
            if(fast->val!=slow->val)
            {
                return false;
            }  
            slow=slow->next;
            fast=fast->next;
        } 
        return true;
    }
};