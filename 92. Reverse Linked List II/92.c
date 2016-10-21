/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 <= m <= n <= length of list.

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    
    struct ListNode * buf = NULL;
    struct ListNode * tmp = NULL;
    struct ListNode * sublist = NULL;
    struct ListNode * sublist_head = NULL;
    struct ListNode * cut = NULL;
    int counter = 1;
    
    buf = head;    
    while(buf != NULL){

        printf("counter=%d\n", counter);
     /* 1->2->3->4->5->6 
           h(3)
           4->3
           5->4->3
           1->2->[5->4->3]->6
        */
        if(m==n)
            return head;     
            
        if(counter == m-1 || m == 1){
            if(m == 1){
                printf("a[m-1,%d]=%d simple case\n",m);
            }else{
                cut = buf;
                printf("a[m-1,%d]=%d\n",counter,cut->val);
            }

        }
        
        //create sublist head
        if(counter == m){
            sublist = buf;
            buf = buf->next;
            sublist->next = NULL;            
            printf("a[m,%d]=%d\n",counter,sublist->val);
        }
        
        //reverse add element to sublist
        if((counter > m && counter <= n)){
            tmp = buf;
            buf = buf->next; 
            tmp->next = sublist;
            sublist = tmp;
            sublist_head = sublist;

            if(counter == n){
                if(cut)
                    cut->next = sublist;
          
                while(sublist && sublist->next){
                    sublist = sublist->next;
                }
                sublist->next = buf;
 
            }
            
        }

        if(counter < m || counter > n)
            buf = buf->next;
            
        counter++;
    } 

    if(m == 1){
        return sublist_head;
    }else{
        return head;
    }

    
}

