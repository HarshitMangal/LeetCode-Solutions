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
      ListNode* reverse(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode*curr=head;
        ListNode*pre=NULL;
        while(curr!=NULL){

          ListNode*next=curr->next;
          curr->next=pre;
          pre=curr;
          curr=next;

        }
        return pre;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*temp=head;
        ListNode*a=NULL;
        ListNode*b=NULL;
        ListNode*c=NULL;
        ListNode*d=NULL;
        int idx=1;
        while(temp!=NULL){
            if(idx==left-1) a=temp;
            if(idx==left)   b=temp;
            if(idx==right) c=temp;
            if(idx==right+1) d=temp;
            idx++;
            temp=temp->next;
        }
        if(a!=NULL) a->next=NULL;
        c->next=NULL;
        c=reverse(b);
        if(a!=NULL)
         a->next=c;
       b->next=d;
       if(a!=NULL) return head;
       return c;
    }
};