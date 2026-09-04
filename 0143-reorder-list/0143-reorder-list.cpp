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
   ListNode* reverse(ListNode*head){
    ListNode*next=head;
    ListNode*curr=head;
    ListNode*pre=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    return pre;
   }
    void reorderList(ListNode* head1) {
        if(head1==NULL) return ;
        ListNode*head=head1;
         ListNode*slow=head;
         ListNode*fast=head;
         while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
         }
         ListNode*second=slow->next;
         slow->next=NULL;
         ListNode*temp=reverse(second);
         ListNode*dummy=new ListNode(-1);
         ListNode*temp1=dummy;
         while(temp!=NULL){
            temp1->next=head;
            temp1=temp1->next;
            head=head->next;
            temp1->next=temp;
            temp=temp->next;
            temp1=temp1->next;
         }
         if(head!=NULL) temp1->next=head;
         head1=dummy->next;

    }
};