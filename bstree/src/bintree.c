#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

BTNode * BTree_new(int value)
{
    BTNode *self = malloc(sizeof(BTNode));
    if (self == NULL)
    {
        abort();
    }
    self->value = value;
    self->left = NULL;
    self->right = NULL;
    
    return self;
}

void BTree_free(BTNode * self)
{
    if(self != NULL) 
    {
        free(self);
    }
}
