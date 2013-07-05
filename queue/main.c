#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct MonStruct_str MonStruct;

struct MonStruct_str {
    TAILQ_ENTRY(MonStruct) entry;
    int i;
};

TAILQ_HEAD(HeadStruct, MonStruct) head;

int main(int argc, char **argv)
{
    MonStruct a[50];
    int i;
    
    TAILQ_INIT(&head);
    
    for (i= 0; i < 50; i++) {
        a[i].i = i;
        TAILQ_INSERT_TAIL(head, &a[i], entry);
    }
    
    printf("last: %d - %d\n", TAILQ_LAST(head, HeadStruct)->i, *head->tqh_last);
}
