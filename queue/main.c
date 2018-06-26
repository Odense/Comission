#include "queue.h"
#include <time.h>
#include <stdio.h>

int main(void)
{
    srand(time(NULL));

    int a = -10;
    int b = 10;

    Queue * queue = Queue_new(10);

    for (int i = 0; i < 10; i++)
    {
        EnQueue(queue, rand() % (b - a + 1) + a);
    }

    Queue_print(queue);

    printf("%d dequeued from queue\n", DeQueue(queue));
 
    printf("Front item is %d\n", Queue_frontEl(queue));
    printf("Rear item is %d\n", Queue_rearEl(queue));

    return 0;
}
