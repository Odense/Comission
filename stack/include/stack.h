#pragma once

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <check.h>

typedef struct __Stack Stack;

Stack * Stack_new(void);

void Stack_free(Stack * self);

void Stack_push(Stack * self, int val);

int Stack_peek(Stack * self);

int Stack_pop(Stack * self);

bool Stack_isEmpty(Stack * self);