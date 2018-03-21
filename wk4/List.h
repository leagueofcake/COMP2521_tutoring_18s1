typedef struct ListNode *Link;
 
typedef struct ListNode {
    int value;
    Link next;
} ListNode;
 
typedef Link List;
 
#define head(L)  (empty(L) ? -1 : (L)->value)
#define tail(L)  (empty(L) ? NULL : (L)->next)
#define empty(L) ((L) == NULL)
 
// display the value contained in a ListNode
#define show(V) { printf("%d",(V)); }
 
// create a new ListNode containing supplied value
// prints error and exit()s if can't create a ListNode
Link newNode(int val);
