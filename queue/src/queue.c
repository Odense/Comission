#include "queue.h"
#include <assert.h>

struct __Queue
{
    int front, rear, size, capacity;
    int * array;
};

Queue * Queue_new(int capacity)
{
    Queue * self = (Queue *)malloc(sizeof(Queue));
    self->capacity = capacity;
    self->front = self->size = 0;
    self->rear = capacity - 1;
    self->array = (int *)malloc(self->capacity * sizeof(int));

    return self;
}

bool Queue_isFull(Queue * self)
{
    if (self->size == self->capacity)
    {
        return true;
    }

    return false;
}

bool Queue_isEmpty(Queue * self)
{
    if (self->size == 0)
    {
        return true;
    }

    return false;
}

void EnQueue(Queue * self, int value)
{
    if (Queue_isFull(self))
    {
        return;
    }

    self->rear = (self->rear + 1)%self->capacity;
    self->array[self->rear] = value;
    self->size = self->size + 1;
}

int DeQueue(Queue * self)
{
    if (Queue_isEmpty(self))
    {
        return 0;
    }

    int value = self->array[self->front];
    self->front = (self->front + 1)%self->capacity;
    self->size = self->size - 1;

    return value;
}

int Queue_frontEl(Queue * self)
{
    if (Queue_isEmpty(self))
    {
        return 0;
    }

    return self->array[self->front];
}

int Queue_rearEl(Queue * self)
{
    if (Queue_isEmpty(self))
    {
        return 0;
    }

    return self->array[self->rear];
}

int Queue_At(Queue * self, size_t index)
{
    assert(index < self->size);
    
    return self->array[index];
}

int Queue_size(Queue * self)
{
    return self->size;
}

void Queue_print(Queue * self)
{
    if (Queue_isEmpty(self))
    {
        printf("Queue is empty!\n");
    }

    for (int i = 0; i < Queue_size(self); i++)
    {
        printf("%i, ", Queue_At(self, i));
    }

    puts("");
}