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
        if(head==NULL) return NULL;
        ListNode*temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len==n) return head->next;
        //loop chaleghe
        temp=head;
        for(int i=0;i<(len-n-1);i++){
          temp=temp->next;
        }
        
       if(temp->next!=NULL) temp->next=temp->next->next;
        return head;
    }
};