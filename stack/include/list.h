#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct __List List;

List * List_new(void);

void List_free(List * self);

void List_add(List * self, int value);

void List_insert(List * self, size_t index, int value);

void List_compare(List * list1, List * list2, List * list3);

void List_merge(List * list1, List * list2, List * list3);

bool List_contains(List * self, int value);

void List_remove_duplicates(List * self);

int List_removeAt(List * self, size_t index);

size_t List_count(List * self);

int List_at(List * self, size_t index);

void List_print(List *self);

void List_remove_negative(List *self);

bool isUnique(List * self, size_t index);

int List_find_min(List * self);

int List_find_max(List * self);