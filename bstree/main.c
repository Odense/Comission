#include "bstree.h"
#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int a = -100;
    int b = 100;

    BSTree * tree = BSTree_new();

    for (int i = 0; i < 10; i++)
    {
        BSTree_insert(tree, rand() % (b - a + 1) + a);
    }

    BSTree_printFormat(tree);

    BSTree_clear(tree);

    for (int i = 0; i < 10; i++)
    {
        BSTree_insert(tree, rand() % (b - a + 1) + a);
    }

    puts("-------------------------------");

    BSTree_printFormat(tree);

    puts("-------------------------------");

    for (int i = -10; i <= 10; i++)
    {
        BSTree_find(tree, i);
    }

    for (int i = -10; i <= 10; i++)
    {
        BSTree_remove_element(tree, i); 
    }

    puts("//-------------------------------//");

    BSTree_printFormat(tree);

    printf("Min el is: %i\n", BSTree_min_value(tree));

    printf("Max el is: %i\n", BSTree_max_value(tree));

    BSTree_clear(tree);

    BSTree_free(tree);

    return 0;
}