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

int main()
{
    struct forest_t forest;
    forest_init(&forest, tree_data_compare_str);

    char buf[0x400];
    int N = 0;
    fgets(buf, sizeof buf, stdin);
    sscanf(buf, "%d", &N);
    FOR (int, i, 0, N) {
        fgets(buf, sizeof buf, stdin);
        if (feof(stdin))
            break;
        if (ferror(stdin))
            ABORT("input error");

        *strchr(buf, '\n') = '\0';

        forest_insert_str(&forest, buf);

        // putchar('>');
        // tree_postorder((struct node_t*) forest.avl_tree->avl_root);
        // puts("");
    }

    tree_postorder((struct node_t*) forest.bst_tree->bst_root);
    puts("");
    tree_postorder((struct node_t*) forest.avl_tree->avl_root);
    puts("");
    tree_postorder((struct node_t*) forest.rb_tree->rb_root);
    puts("");

    return 0;
}
