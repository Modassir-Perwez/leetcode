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
    ListNode* findMiddle(ListNode* head){
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    //step 3
    ListNode* mergeSortList(ListNode* list1,ListNode* list2){
    //      ListNode* dummyNode = new ListNode(-1);
    //      ListNode* temp = dummyNode;

    // // Traverse both lists simultaneously
    // while (list1 != nullptr && list2 != nullptr) {
    //     // Compare elements of both lists and
    //     // link the smaller node to the merged list
    //     if (list1->val <= list2->val) {
    //         temp->next = list1;
    //         list1 = list1->next;
    //     } else {
    //         temp->next = list2;
    //         list2 = list2->next;
    //     }
    //     // Move the temporary pointer
    //     // to the next node
    //     temp = temp->next; 
    // }

    // // If any list still has remaining
    // // elements, append them to the merged list
    // if (list1 != nullptr) {
    //     temp->next = list1;
    // } else {
    //     temp->next = list2;
    // }
    // // Return the merged list starting 
    // // from the next of the dummy node
    // return dummyNode->next;
     if(list1==NULL || list2==NULL){
            return list1 ? list1:list2;
        }
        if(list1->val < list2->val){
            list1->next=mergeSortList(list1->next,list2);
            return list1;
        }
        else{
              list2->next=mergeSortList(list1,list2->next);
              return list2;
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr){
            return head ;
        }
        if(head->next==nullptr){
            return head;
        }
        //sort karna hai
        //based on merge algorithm 1 diveide ,sort, merge
        ListNode* middle=findMiddle(head);
        ListNode* right=middle->next;
        middle->next=NULL;
        ListNode* left=head;
        left=sortList(left);
        right=sortList(right);
        return mergeSortList(left,right);

    }
};