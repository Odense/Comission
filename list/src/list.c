#include "list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct __List
{
    int *array;
    int capacity;
    int length;
};

static void Fault(void)
{
    char *string = "NULL pointer assignment\n";
    fwrite(string, 1, 25, stderr);
    abort();
}

List * List_new(void)
{
    List *self = malloc(sizeof(List));
    if(self == NULL)
    {
        Fault();
    }

    self->array = malloc(sizeof(int) * 10);
    if(self->array == NULL)
    {
        Fault();
    }

    self->capacity = 10;
    self->length = 0;

    return self;
}

void List_free(List * self)
{
    if(self == NULL)
    {
        assert(0 && "Argument is NULL");
    }

    free(self->array);
    free(self);
}

void List_add(List * self, int value)
{
    if(self == NULL)
    {
        assert(0 && "Argument is NULL");
    }

    if(self->length < self->capacity)
    {
        self->array[self->length] = value;
        self->length++;
    }
}

void List_insert(List * self, size_t index, int value)
{
    if(self == NULL)
    {
        assert(0 && "Argument is NULL");
    }

    if(self->length < self->capacity)
    {
        for (int i = self->length; i > index; i--)
        {
            self->array[i] = self->array[i - 1];
        }
    }

    self->array[index] = value;
    self->length++;
}

int List_at(List * self, size_t index)
{
    assert(index < self->length);

    return self->array[index];
}

int List_removeAt(List * self, size_t index)
{
    for (int i = index; i < self->length - 1; i++)
    {
        self->array[i] = self->array[i + 1];
    }

    self->length--;

    return self->length;
}

size_t List_count(List * self)
{
    return self->length;
}

void List_compare(List * list1, List * list2, List * list3)
{
    int size1 = List_count(list1);

    for (int i = 0; i < size1; i++)
    {
        int el = List_at(list1, i);

        if (List_contains(list2, el) && !List_contains(list3, el))
        {
            List_add(list3, el);
        }
    }
}

bool isUnique(List * self, size_t index)
{
    int indexel = List_at(self, index);
    int length = List_count(self);

    for (int i = index + 1; i < length; i++)
    {
        if (List_at(self, i) == indexel)
        {
            return false;
        }
    }

    return true;
}

void List_remove_duplicates(List * self)
{
    for (int i = 0; i < List_count(self); i++)
    {
        if (!isUnique(self, i))
        {
            List_removeAt(self, i);
            i--;
        }
    }
}

void List_merge(List * list1, List * list2, List * list3)
{
    int size1 = List_count(list1);
    int size2 = List_count(list2);

    for (int i = 0; i < size1; i++)
    {
        int el = List_at(list1, i);

        if (List_contains(list1, el) && !List_contains(list2, el) && !List_contains(list3, el))
        {
            List_add(list3, el);
        }
    }

    for (int j = 0; j < size2; j++)
    {
        int el = List_at(list2, j);

        if (List_contains(list2, el) && !List_contains(list1, el) && !List_contains(list3, el))
        {
            List_add(list3, el);
        }        
    }
}

void List_print(List * self)
{
    if(self == NULL)
    {
        fwrite("NULL pointer assignment\n", 1, 25, stderr);
        abort();
    }

    int size = List_count(self);
    for (int i = 0; i < size; i++)
    {
        printf("%i, ", List_at(self, i));
    }
    puts("");
}

void List_remove_negative(List * self)
{
    if(self == NULL)
    {
        fwrite("NULL pointer assignment\n", 1, 25, stderr);
        abort();
    }
    int length = List_count(self);
	for (int i = 0; i < length; i++) 
    {
		if (List_at(self, i) < 0) 
        {
			List_removeAt(self, i);
			length = List_count(self);
			i--;
		}
	}
}

bool List_contains(List * self, int value)
{
    int length = List_count(self);

    for (int i = 0; i < length; i++)
    {
        if(List_at(self, i) == value)
        {
            return true;
        }
    }

    return false;
}

int List_find_min(List * self)
{
    int length = List_count(self);

    int min = List_at(self, 0);

    for (int i = 0; i < length; i++)
    {
        if (min > List_at(self, i))
        {
            min = List_at(self, i);
            i++;
        }
    }

    return min;
}

int List_find_max(List * self)
{
    int length = List_count(self);

    int max = List_at(self, 0);

    for (int i = 0; i < length; i++)
    {
        if (max < List_at(self, i))
        {
            max = List_at(self, i);
            i++;
        }
    }

    return max;
}
