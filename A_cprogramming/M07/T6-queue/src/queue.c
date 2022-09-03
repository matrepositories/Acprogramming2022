#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enqueue(struct studentqueue *q, const char *name)
{
    struct studentqueue *newnode = (struct studentqueue*)malloc(sizeof(struct studentqueue));
    if(newnode == NULL)
    {
        return 0;
    }
    while(q->next)
    {
        q = q->next;
    }    
    q->next = newnode;
    newnode->next = NULL;
    newnode->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(newnode->name, name);
    return 1;

}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size)
{
    if (q->next == NULL)
    {
        return 0;
    }
    struct studentqueue *ptr = q->next; 
    strncpy(buffer, q->next->name, size);
    q->next = q->next->next;
    free(ptr->name);
    free(ptr);
    return 1;

}