#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// libavl
#include "avl.h"
#include "bst.h"
#include "rb.h"

//
#include "tools.h"

int tree_data_compare_str(const void* pa, const void* pb, void* param)
{
    const char* a = (const char*) pa;
    const char* b = (const char*) pb;
    return strcmp(a, b);
}

int tree_data_compare_int(const void* pa, const void* pb, void* param)
{
    int a = *(const int*) pa;
    int b = *(const int*) pb;

    if (a < b)
        return -1;
    else if (a > b)
        return +1;
    else
        return 0;
}

void tree_postorder_pretty(const struct node_t* node, int depth)
{
    if (node == NULL)
        return;

    printf("%*c", depth * 2, ' ');
    printf("%s ", (const char*) node->data);
    if (node->link[0] != NULL || node->link[1] != NULL) {
        printf("(\n");

        tree_postorder_pretty(node->link[0], depth + 1);

        printf("%*c", depth * 2, ' ');
        printf(", \n");

        tree_postorder_pretty(node->link[1], depth + 1);

        printf("%*c", depth * 2, ' ');
        printf(")");
    }
    printf("\n");
}

void tree_postorder(const struct node_t* node)
{
    if (!node)
        return;
    printf("%s ", node->data);
    if (node->link[0] || node->link[1]) {
        putchar('(');
        tree_postorder(node->link[0]);
        putchar(',');
        putchar(' ');
        tree_postorder(node->link[1]);
        putchar(')');
    }
}

void tree_data_destroy(void* item, void* param)
{
    free(item);
}

int tree_height(const struct node_t* node)
{
    if (!node->link[0] && !node->link[1])
        return 0;
    else if (!node->link[0])
        return tree_height(node->link[1]) + 1;
    else if (!node->link[1])
        return tree_height(node->link[0]) + 1;
    else
        return max(tree_height(node->link[0]), tree_height(node->link[1])) + 1;
}

void forest_init(struct forest_t* forest, base_comparison_func* comp)
{
    forest->bst_tree = bst_create(comp, NULL, NULL);
    forest->avl_tree = avl_create(comp, NULL, NULL);
    forest->rb_tree = rb_create(comp, NULL, NULL);
}

void forest_insert_int(struct forest_t* forest, int x)
{
    int* data;

    data = malloc(sizeof(int));
    *data = x;
    bst_insert(forest->bst_tree, data);

    data = malloc(sizeof(int));
    *data = x;
    avl_insert(forest->avl_tree, data);

    data = malloc(sizeof(int));
    *data = x;
    rb_insert(forest->rb_tree, data);
}

void forest_insert_str(struct forest_t* forest, const char* str)
{
    char* s;

    s = strdup(str);
    bst_probe(forest->bst_tree, s);

    s = strdup(str);
    avl_probe(forest->avl_tree, s);

    s = strdup(str);
    rb_probe(forest->rb_tree, s);
}

void forest_delete_int(struct forest_t* forest, int x)
{
    free(bst_delete(forest->bst_tree, &x));
    free(avl_delete(forest->avl_tree, &x));
    free(rb_delete(forest->rb_tree, &x));
}

void forest_height(const struct forest_t* forest, int h[3])
{
    h[0] = tree_height((struct node_t*) forest->bst_tree->bst_root);
    h[1] = tree_height((struct node_t*) forest->avl_tree->avl_root);
    h[2] = tree_height((struct node_t*) forest->rb_tree->rb_root);
}

void forest_destroy(struct forest_t* forest)
{
    bst_destroy(forest->bst_tree, tree_data_destroy);
    avl_destroy(forest->avl_tree, tree_data_destroy);
    rb_destroy(forest->rb_tree, tree_data_destroy);
}
