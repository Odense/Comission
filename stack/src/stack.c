#include "stack.h"
#include "list.h"
#include <stdio.h>

struct __Stack
{
    List * list;
};

bool Stack_isEmpty(Stack * self) 
{
    return List_count(self->list) == 0;
}

Stack * Stack_new(void) 
{
    Stack * self = malloc(sizeof(Stack));
    if (self == NULL) return NULL;
    self->list = List_new();

    return self;
}

void Stack_free(Stack * self) 
{
    if(self != NULL) 
    {
        if(self->list != NULL) 
        {
            List_free(self->list);
        }
        free(self);
    }
}

void Stack_push(Stack * self, int val) 
{
    if (self != NULL) 
    {
        List_add(self->list, val);
    }
}

int Stack_pop(Stack * self) 
{
    if(self != NULL) 
    {
        return List_removeAt(self->list, List_count(self->list) - 1);
    }

    return 0;
}

int Stack_peek(Stack * self) 
{
    if (self != NULL) 
    {
        int lastIndex = List_count(self->list) - 1;

        return List_at(self->list, lastIndex);
    }

    return 0;
}
