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
//using samling method
     ListNode*head;
    Solution(ListNode* head) {
          this->head=head;
    }
    
    int getRandom() {
        ListNode*curr=head;
        int count=1;
        int ans=curr->val;
        while(curr!=NULL){
            if(rand()%count==0){
                ans=curr->val;
            }
            count++;
            curr=curr->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */