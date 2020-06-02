#pragma once

#include "base.h"

int tree_data_compare_str(const void* pa, const void* pb, void* param);
int tree_data_compare_int(const void* pa, const void* pb, void* param);
void tree_data_destroy(void* item, void* param);

void tree_postorder_pretty(const struct node_t* node, int depth);
void tree_postorder(const struct node_t* node);

int tree_height(const struct node_t* node);


void forest_init(struct forest_t* forest, base_comparison_func* comp);
void forest_destroy(struct forest_t* forest);

void forest_insert_int(struct forest_t* forest, int x);
void forest_insert_str(struct forest_t* forest, const char* str);

void forest_delete_int(struct forest_t* forest, int x);

void forest_height(const struct forest_t* forest, int h[3]);
