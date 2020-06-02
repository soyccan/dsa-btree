#pragma once

#include <stddef.h>

#ifndef LIBAVL_ALLOCATOR
#define LIBAVL_ALLOCATOR
/* Memory allocator. */
struct libavl_allocator {
    void* (*libavl_malloc)(struct libavl_allocator*, size_t libavl_size);
    void (*libavl_free)(struct libavl_allocator*, void* libavl_block);
};
#endif

typedef void base_item_func(void* item, void* param);
typedef int base_comparison_func(const void* a, const void* b, void* param);

/* superclass of avl_node, bst_node, rb_node */
struct node_t {
    struct node_t* link[2];  /* Subtrees. */
    void* data;              /* Pointer to data. */
    unsigned char padding[]; /* extra data of each subclass */
};

/* superclass of avl_table, bst_table, rb_table */
struct tree_t {
    struct node_t* root;            /* Tree's root. */
    base_comparison_func* compare;  /* Comparison function. */
    void* param;                    /* Extra argument to |avl_compare|. */
    struct libavl_allocator* alloc; /* Memory allocator. */
    size_t count;                   /* Number of items in tree. */
    unsigned long generation;       /* Generation number. */
};

struct forest_t {
    struct bst_table* bst_tree;
    struct avl_table* avl_tree;
    struct rb_table* rb_tree;
};
