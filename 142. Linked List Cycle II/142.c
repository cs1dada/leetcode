/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode *detectfn(struct ListNode *head){
    struct ListNode * p1 = NULL;
    struct ListNode * p2 = NULL;
    p1=p2=head;
    
    //detect cycle
    while(p1 && p1->next && p1->next->next){
        p1 = p1->next->next; //2 step
        p2 = p2->next;       //1 step
        if(p1 == p2){
            return p2;
        }
    }
    
    return NULL;
 }
 
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode * p1 = NULL;
    struct ListNode * p2 = NULL;
    struct ListNode * hit = NULL;

    //detect cycle
    hit = detectfn(head);
    
    if(hit == NULL){
        //no cycle
        return NULL;
    }else{
        //with cycle find satrt
        p1 = hit;
        p2 = head;
        while(p1 && p2 && p1 != p2){
           p1 = p1->next;
           p2 = p2->next;
        }
    }
    
    return p1;
    
}
