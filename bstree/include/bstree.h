#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct __BSTree BSTree;

BSTree * BSTree_new(void);

void BSTree_free(BSTree * self);

void BSTree_insert(BSTree * self, int key);

void BSTree_clear(BSTree * self);

void BSTree_add(BSTree * self, int value);

void BSTree_printFormat(BSTree * self);

int BSTree_find(BSTree * self, int value);

int BSTree_min_value(BSTree * self);

int BSTree_max_value(BSTree * self);

void BSTree_remove_element(BSTree * self, int key);