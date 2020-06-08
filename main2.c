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
    forest_init(&forest, tree_data_compare_int);

    int h[3][3];

    // insert
    FOR (int, i, 1, 2049) {
        forest_insert_int(&forest, i);
    }
    forest_height(&forest, h[0]);

    // delete
    FOR (int, i, 1, 1025) {
        forest_delete_int(&forest, i);
    }
    forest_height(&forest, h[1]);

    // insert
    FOR (int, i, 2049, 4097) {
        forest_insert_int(&forest, i);
    }
    forest_height(&forest, h[2]);

    char* name[] = {"bst", "avl", "rb"};
    FOR (int, i, 0, 3) {
        printf("%s", name[i]);
        FOR (int, j, 0, 3)
            printf(" %d", h[j][i]);
        puts("");
    }

    return 0;
}
