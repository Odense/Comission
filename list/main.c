#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int a = -10;
    int b = 10;

    List * list1 = List_new();

    List * list2 = List_new();

    for (int i = 0; i < 10; i++)
    {
        List_add(list1, rand() % (b - a + 1) + a);
        List_add(list2, rand() % (b - a + 1) + a);
    }

    List * list3 = List_new();

    List_compare(list1, list2, list3);

    List_print(list1);

    List_print(list2);

    List_print(list3);

    List * list4 = List_new();

    List_merge(list1, list2, list4);

    List_print(list4);

    List_remove_duplicates(list1);

    puts("//----------------//");

    List_print(list1);

    puts("//----------------//");

    printf("Min el is: %i\n", List_find_min(list1));

    printf("Max el is: %i\n", List_find_max(list1));

    puts("-----------------------------------");

    List_remove_negative(list1);

    List_print(list1);

    List_remove_negative(list2);

    List_print(list2);

    List_remove_negative(list3);

    List_print(list3);

    List_remove_negative(list4);

    List_print(list4);

    List_free(list1);

    List_free(list2);

    List_free(list3);

    List_free(list4);

    return 0;
}
