# Java to C Primer - Linked Lists
# Preface and TL;DR
This is mainly a comparison and translation of some of the linked list functions covered in the labs this week for the people that have only seen Java so far. For simplicity, some of the functions may look different to what you find in Lab 2 (mainly the use of `typedef IntListRep *IntList;` in the labs which I've excluded in the examples below). 
* Generally need to allocate memory in C when creating a new node/list - Java handles this for you. This also means you have to free the memory once you have finished with it. 
* Since C requires you to allocate memory, you'll be working with pointers to the struct instead of directly working with the struct.

Hopefully this will prove useful! 

## Defining an IntListNode
### Java
Standard class definition with a constructor. 
```Java
public class IntListNode {
    int data;
    IntListNode next;
    
    public IntListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

// Create a new IntListNode using the constructor
IntListNode n = new IntListNode(42);
```

### C
In C we can't really attach methods to a struct, so we need a separate function to create a new IntListNode (act as a constructor). 

Any non-primitive types (non `int`, `char`, etc.) that we would like to reuse across functions need to have memory allocated for them on the heap using `malloc`. If it succeeds, `malloc` returns a pointer specifying what address the allocated memory is at, otherwise it returns `NULL` (e.g. not enough memory to allocate requested size). 

Once we have a pointer to some allocated memory, we use the arrow operator (`->`) to access properties of the struct - compare how `data` and `next` are set in the two languages. 

Since we allocate memory to create our structs, we also need to free the memory we have allocated for the struct once we are done with it, by using `free()` on the pointer we received from `malloc`. This is also something you don't have to do in Java, since its built in garbage collector handles it for you. 

```c
struct IntListNode {
    int data; 
    struct IntListNode *next;
};

struct IntListNode *newIntListNode(int data) {
    struct IntListNode *n;                  // Declare a pointer to an IntListNode
    n = malloc(sizeof(struct IntListNode)); // Allocate enough memory to store an IntListNode
    assert(n != NULL);                      // Check that malloc succeeded
    n->data = v;
    n->next = NULL;
    return n;
}

// Create a new IntListNode using our function
struct IntListNode *n = newIntListNode(42);
// Use the node...
free(n); // Free the memory we allocated once we are done with it
```

## Defining an IntListRep
### Java
```Java
public class IntListRep {
    int size;
    IntListNode first;
    IntListNode last;
    
    public IntListRep () {
        size = 0;
        first = null;
        last = null;
    }
}

// Create a new IntListRep using the constructor
IntListRep list = new IntListRep();
```

### C
```C
struct IntListRep {
    int size;
    struct IntListNode *first;
    struct IntListNode *last;
}

struct IntListRep *newIntListRep () {
    struct IntListRep *L;                  // Declare a pointer to an IntListNode
    L = malloc(sizeof(struct IntListRep)); // Allocate enough memory to store an IntListRep
    assert(L != NULL);                     // Check that malloc succeeded
    L->size = 0;
    L->first = NULL;
    L->last = NULL;
    return L;
}

// Create a new IntListRep using our function
struct IntListRep *list = newIntListRep();
// Use the list...
free(list); // Free the memory we allocated once we are done with it
// We would also need to free any nodes that we have used in our list
```

## Iterating through a linked list
You'll notice the code is pretty similar - main difference is that we operate on pointers in C, and use `->` to access properties from the pointers. 
### Java
```Java
// Assume we have an IntListRep called list with a head and tail
IntListNode curr = list.head;
while (curr != null) {
    System.out.println(curr.data);
    curr = curr.next;
}
```

### C
```C
// Assume we have a pointer to an IntListRep called list with a head and tail
IntListNode *curr = list->head;
while (curr != NULL) {
    printf("%d\n", curr->data);
    curr = curr->next;
}
```
