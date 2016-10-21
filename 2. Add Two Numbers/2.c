/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    typedef struct ListNode sListNode;
    
    int carry = 0;
    struct ListNode * headx =l1;
    struct ListNode * heady =l2;
    
    struct ListNode * element = NULL;
    struct ListNode * result = NULL;
    struct ListNode * result_head = NULL;
    
    //case1: NULL list
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
        
    //case2: longer list
    while (headx!=NULL) {
        // x->[1]->[2]->[3]->[4]->NULL
        // y->[1]->[2]->NULL
        if(heady == NULL)
            break;
        
        //alloc memory    
        element = (sListNode *)malloc(sizeof(sListNode));
        
        //callculate sum
        element->val = (headx->val + heady->val + carry)%10;
        carry = (headx->val + heady->val + carry)/10;
        printf("headx->val=%d, heady->val=%d, element->val=%d, carry=%d\n", headx->val, heady->val, element->val, carry);
        element->next = NULL;
        
        //first
        if (result == NULL) {
            printf("first\n");
            result = element;
            result_head = result;
        }//[1/result]->[2]->[3]->[4/head]->NULL
        else {
            printf("last\n");
            result_head->next = element;
            result_head = element;
        }
        
        headx = headx->next;
        heady = heady->next;
    }
   printf("============================================\n");  
    //y>x
    if (heady!=NULL) {
        printf("y>x \n");
        while (heady!=NULL) {
            element = (sListNode *)malloc(sizeof(sListNode));
            
            element->val = (heady->val + carry)%10;
            carry = (heady->val + carry)/10;
            element->next = NULL;        
            printf("heady->val=%d, element->val=%d, carry=%d\n", heady->val, element->val, carry);
            
             //first
            if (result == NULL) {
                result = element;
                result_head = result;
            }//[1/result]->[2]->[3]->[4/head]->NULL
            else {
                result_head->next = element;
                result_head = element;
            }
        
            heady = heady->next;  
        }
    }//x>y
    else if(heady == NULL && headx!=NULL) {
        printf("x>y \n");        
        while (headx!=NULL) {
            element = (sListNode *)malloc(sizeof(sListNode));
            
            element->val = (headx->val + carry)%10;
            carry = (headx->val + carry)/10;
            element->next = NULL;        
            printf("headx->val=%d, element->val=%d, carry=%d\n", headx->val, element->val, carry);
            
             //first
            if (result == NULL) {
                result = element;
                result_head = result;
            }//[1/result]->[2]->[3]->[4/head]->NULL
            else {
                result_head->next = element;
                result_head = element;
            }
        
            headx = headx->next;  
        }        
    }
    
    //case3: overflow 
    if (carry) {
        element = (sListNode *)malloc(sizeof(sListNode));
        element->val = 1;
        element->next = NULL;
        
        result_head->next = element;
        result_head = element;
    }
    
    result_head = result;
    while (result_head != NULL) {
        printf("[%d]->", result_head->val);
        result_head = result_head->next;
    }
    return result;
    
    //case3: overflow
        
    
}

