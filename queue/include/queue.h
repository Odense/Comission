#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct __Queue Queue;

Queue * Queue_new(int capacity);

bool Queue_isFull(Queue * self);

bool Queue_isEmpty(Queue * self);

void EnQueue(Queue * self, int value);

int DeQueue(Queue * self);

int Queue_frontEl(Queue * self);

int Queue_rearEl(Queue * self);

void Queue_print(Queue * self);

int Queue_size(Queue * self);

int Queue_At(Queue * self, size_t index);