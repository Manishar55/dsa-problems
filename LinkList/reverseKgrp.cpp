class Solution {
public:
    int getLength(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        int len=getLength(head);
        if(k>len){
            return head;
        }

        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*forward=curr->next;

        int count=0;
        while(count<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }

        //Rec
        if(forward!=NULL){
            head->next=reverseKGroup(forward, k);
        }

        return prev;
    }
};