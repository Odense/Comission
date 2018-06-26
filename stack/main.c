#include "stack.h"
#include <time.h>

int main(void)
{
    srand(time(NULL));

    Stack * stack = Stack_new();

    int a = -10;

    int b = 10;

    for (int i = 0; i < 10; i++)
    {
        Stack_push(stack, rand() % (b - a + 1) + a);
    }

    //Stack_print(stack);

    Stack_free(stack);

    return 0;
}
