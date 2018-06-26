#include "bstree.h"
#include "bintree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct __BSTree 
{
    BTNode * root;
};

BSTree * BSTree_new(void)
{
    BSTree * self = malloc(sizeof(BSTree));
    if(self == NULL) 
    {
        fprintf(stderr, "Out of Memory!\n");
        abort();
    }
    self->root = NULL;
    return self;
}

void BSTree_free(BSTree * self)
{
    if(self != NULL) 
    {
        free(self);
    } 
}

static void insert(BTNode * node, int key)
{
    if (key < node->value)
    {
        if (node->left == NULL)
        {
            node->left = BTree_new(key);
        }
        else
        {
            insert(node->left, key);
        }
    }
    else if (key > node->value)
    {
        if (node->right == NULL)
        {
            node->right = BTree_new(key);
        }
        else
        {
            insert(node->right, key);
        }
    }
    else
    {
        fprintf(stderr, "Not unique!\n");
        abort();
    }
}

void BSTree_insert(BSTree * self, int key)
{
    if (self->root == NULL)
    {
        self->root = BTree_new(key);
    }
    else
    {
        insert(self->root, key);
    }
}

static void Print_level(BTNode * node, int level)
{
    for (int i = 0; i < level; i++)
    {
        putchar('.');
        putchar('.');
    }
    if (node == NULL)
    {
        printf("(null)\n");
    }
    else
    {
        printf("%i\n", node->value);
        if (node->left || node->right)
        {
            level++;
            Print_level(node->left, level);
            Print_level(node->right, level);
        }
    }
}

void BSTree_printFormat(BSTree * self)
{
    Print_level(self->root, 0);
}

static void clear(BTNode * node) 
{
    if (node->left) 
    {
        clear(node->left);
    }
    if (node->right) 
    {
        clear(node->right);
    }

    BTree_free(node);
}

void BSTree_clear(BSTree *self)
{
    clear(self->root);
    self->root = NULL;
}

int BSTree_find(BSTree * self, int value)
{
    BTNode * findnode = self->root;
    for (;;)
    {
        if (findnode == NULL)
        {
            printf("%i -\n", value);
            return 0;
        } 
        else if (value == findnode->value)
        { 
            printf("%i found\n", value);
            return 1; 
        }
        else if (value > findnode->value)
        { 
            findnode = findnode->right; 
        }
        else if (value < findnode->value)
        {
            findnode = findnode->left;
        }
    }
}

BTNode * minValueNode(BTNode * self)
{
    BTNode * curr = self;

    while (curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

BTNode * Remove_element(BTNode * self, int key) //first param to input: self->root
{
    if (self == NULL) return NULL;

    if (key < self->value)
    {
        self->left = Remove_element(self->left, key);
    }
    
    else if (key > self->value)
    {
        self->right = Remove_element(self->right, key);
    }

    else 
    {
        if (self->left == NULL)
        {
            BTNode * tmp = self->right;
            free(self);

            return tmp;
        }
        else if (self->right == NULL)
        {
            BTNode * tmp = self->left;
            free(self);

            return tmp;
        }

        BTNode * tmp = minValueNode(self->right);

        self->value = tmp->value;

        self->right = Remove_element(self->right, tmp->value);
    }

    return self;
}

void BSTree_remove_element(BSTree * self, int key) 
{
    Remove_element(self->root, key);
}

int BSTree_min_value(BSTree * self)
{
    return minValueNode(self->root)->value;
}

int BSTree_max_value(BSTree * self)
{
    BTNode * curr = self->root;

    while (curr->right != NULL)
    {
        curr = curr->right;
    }

    return curr->value;
}