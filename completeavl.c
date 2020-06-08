// claiming that inserting 1,2,...,2^k-1 into AVL
// then it's a complete binary tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// libavl
#include "avl.h"
#include "bst.h"
#include "rb.h"

//
#include "base.h"
#include "tools.h"
#include "tree.h"

static void dfs(struct node_t* node)
{
    if (!node)
        return;
    printf("%d ", *(int*) node->data);
    if (node->link[0] || node->link[1]) {
        putchar('(');
        dfs(node->link[0]);
        putchar(',');
        dfs(node->link[1]);
        putchar(')');
    }
}

static void inorder(struct node_t* node)
{
    if (!node)
        return;
    inorder(node->link[0]);
    printf("%d ", *(int*) node->data);
    inorder(node->link[1]);
}

int main()
{
    // struct avl_table* tree = avl_create(tree_data_compare_int, NULL, NULL);
    struct forest_t f;
    forest_init(&f, tree_data_compare_int);

    int N = 0;
    scanf("%d", &N);
    N = 1 << N;
    FOR (int, i, 1, N) {
        forest_insert_int(&f, i);
        dfs(f.avl_tree->avl_root);
        puts("");
    }
    inorder(f.avl_tree->avl_root);
    puts("");

    printf("h=%d\n", tree_height(f.avl_tree->avl_root));

    return 0;
}
