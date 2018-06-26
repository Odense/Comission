#pragma once

typedef struct __BTNode BTNode;

struct __BTNode 
{
    int value;
    BTNode * left;
    BTNode * right;
};

BTNode * BTree_new(int value);

void BTree_free(BTNode *self);