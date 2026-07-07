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
class compare{
    public:
     bool operator()(ListNode*a,ListNode*b){
        return a->val>b->val;
     }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       
       priority_queue<ListNode*,vector<ListNode*>,compare>pq;

       int k=lists.size();
       if(k==0) return nullptr;

       //step 1:starting k k  elements min heap me daaldo

       for(int i=0;i<k;i++){
        if(lists[i]!=NULL){
            pq.push(lists[i]);
        }
       }

        ListNode*head=NULL;
        ListNode*tail=NULL;

       while(!pq.empty()){
          ListNode*top=pq.top();
          pq.pop();

          if(head==NULL){
            head=top;
            tail=top;
            if(head->next){
                pq.push(head->next);
            }
          }
          else{
            tail->next=top;
            tail=top;

            if(tail->next){
                pq.push(tail->next);
            }
          }
       }
      return head;
    }
};
