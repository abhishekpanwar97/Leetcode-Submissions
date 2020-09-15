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
    ListNode* swapPairs(ListNode* head) {
         if(head==NULL || head->next==NULL){
           return head;
        }
        
        ListNode* prev=NULL, *h1=NULL, *h2=NULL, *nextt=NULL;
        ListNode* ans=NULL;
        h1=head;
        h2=head->next;
        while(h1!=NULL){
            nextt=h2->next;
            h2->next=h1;
            h1->next=NULL;
            if(prev==NULL){
                ans=h2;
                prev=h1;
            }else{
                prev->next=h2;
                prev=h1;
            }
            
            h1=nextt;
            if(h1==NULL){
                break;
            }
            h2=h1->next;
            if(h2==NULL){
                prev->next=h1;
                break;
            }
        }
        
        return ans;
   
    }
};