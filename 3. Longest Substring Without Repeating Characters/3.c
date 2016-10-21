/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

typedef struct Entry {
    char value;
    struct Entry* next; 
}NewEntry;

typedef struct HASH_TABLE {
    int size;
    NewEntry **list;
} hashtable;

#define HashTableSize 10


NewEntry *findName(char *Ptr, hashtable *pHead)
{

#if 0//debug  
    printf("debug\n");
    int i = 0;
    NewEntry *slot2 = pHead -> list[7];
    printf("list[7]->");
    while (slot2 != NULL) {
        printf("[%d/%c]->", i, slot2->value);
        slot2 = slot2->next;   
        i++;
    }
    printf("\n");
    
    i = 0;
    slot2 = pHead -> list[8];
    printf("list[8]->");
    while (slot2 != NULL) {
        printf("[%d/%c]->", i, slot2->value);
        slot2 = slot2->next;   
        i++;
    }
    printf("\n");   

    i = 0;
    slot2 = pHead -> list[9];
    printf("list[9]->");
    while (slot2 != NULL) {
        printf("[%d/%c]->", i, slot2->value);
        slot2 = slot2->next;   
        i++;
    }
    printf("\n");        
#endif    

    int index = Hash(Ptr);
    NewEntry *slot = pHead -> list[index];

    //printf("findname: lastname=%s index=%d\n", lastname, index);
    
    while (slot != NULL) {
        if (*Ptr == slot->value) {
            //printf("match!!! *Ptr:%c at  list[%d] \n",*Ptr, index);
            return slot;
        }
        slot = slot->next;
    }

    //printf("Ptr:%c not exist, findName fail \n",*Ptr);
    return NULL;
}

int remove_op(char *Ptr, hashtable *pHead) {
    
    int index = Hash(Ptr);
    //printf("findname: lastname=%s index=%d\n", lastname, index);

    NewEntry *slot = pHead -> list[index];
    NewEntry *prev = slot;
    
    while (slot != NULL) {
        if (*Ptr == slot->value) {
            //ptr->NULL, 1 element at this slot
            if (slot == pHead -> list[index]) {
                slot->value = NULL;
                //printf("success delete1 *Ptr=%c\n", *Ptr);   
            }
            else {//a->ptr->b->NULL, many elements at this slot
                prev->next = slot->next;
                free(slot);
                //printf("success delete2 *Ptr=%c\n", *Ptr);                
                
            }
            
            return 0;
        }
        prev = slot;
        slot = slot->next;
    }
    
    //printf("Ptr:%c not exist, remove fail \n",*Ptr);
    return -1;    
}

int append(char *Ptr, hashtable *e)
{
    int index = 0;
    //printf("append *Ptr=%c \n", *Ptr);
    
    NewEntry  *addEntry;
    addEntry = (NewEntry *)malloc(sizeof(NewEntry));
    //strcpy(addEntry -> value, Ptr);
    addEntry -> value = *Ptr;
    //printf("append= %c *Ptr=%c ", addEntry -> value, *Ptr);
    
    /* pick slot in hashtable */
    index = Hash(Ptr);
    //printf("index= %d \n", index);
    
    /* insert NewEntry to hashtable*/
    addEntry->next = e->list[index];
    e->list[index] = addEntry;

    return 0;
}

hashtable *HashTable_Init()
{
    printf("HashTable_Init\n");
    hashtable * ht = NULL;
    int i = 0;

    printf("allocate memory\n");
    ht = (hashtable *)malloc(sizeof(hashtable));
    ht -> list = (NewEntry **)malloc(sizeof(NewEntry *) * HashTableSize);
    ht -> size = HashTableSize;

    printf("init to zero\n");
    for (i =0; i < HashTableSize; i++) {
        //memset(ht -> list[i], '\0', sizeof(entry) );
        ht -> list[i] = NULL;
    }

    printf("init ok!!! \n");
    return ht;
}

int Hash (char *Ptr)
{
    int value =0;
    int i = 0;

    value = *Ptr;
    
    return value % HashTableSize;
}


int lengthOfLongestSubstring(char* s) {

    hashtable *ht;
    ht = HashTable_Init();
    
    int stringlength = strlen(s);
    printf("stringlength=%d\n\n", stringlength);
    
    int i=0;
    int j=0;
    int length = 0;
    
    char *ptr = s;
    
    while (i < stringlength && j < stringlength) {
        //[i,j], expand j, until j repeat at [i,j-1]
        //printf("\n\n*(ptr+i)=%c *(ptr+j)=%c\n", *(ptr+i), *(ptr+j));   
        if (findName(ptr+j, ht) ==NULL) { //not repeat
            append(ptr+j, ht); 
            j++; 
            if (length < (j-i))
                length = (j-i);
  
        }
        else {//j repeat at [i,j-1], expand i (remove i from hashtable)
            remove_op(ptr+i, ht);   
            i++;
        }
    }

    
    
    return length;
}

