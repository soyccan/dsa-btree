#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// libavl
#include "avl.h"
#include "bst.h"
#include "rb.h"

//
#include "base.h"
#include "tools.h"
#include "tree.h"


struct forest_t forest;

// i=0: after 1st insertion,
// i=1: after removal
// i=2: after 2nd insertion
// j=0,1,2: bst,avl,rb
int mx[3][3];
int mn[3][3];
int avg[3][3];

int h[3][3];
int Rand[4096 * 10000];
// size = 4*4096*10000 = 16k*10000

void randseq(int n)
{
    // TODO: better random
    // arc4random: native no Darwin, require -lbsd on Linux
    system("dd if=/dev/urandom of=random.bin bs=16k count=10000");
    FILE* f = fopen("random.bin", "r");
    fread(Rand, sizeof(int), n, f);
    fclose(f);
}

int main()
{
    srand(time(NULL));
    randseq(4096 * 10000);

    FOR (int, i, 0, 3) {
        FOR (int, j, 0, 3) {
            mx[i][j] = INT_MIN;
            mn[i][j] = INT_MAX;
            avg[i][j] = 0;
        }
    }

    FOR (int, rnd, 0, 10000) {
        forest_init(&forest, tree_data_compare_int);

        // insert
        FOR (int, i, rnd * 4096, rnd * 4096 + 2048) {
            forest_insert_int(&forest, Rand[i]);
        }
        forest_height(&forest, h[0]);

        // delete
        FOR (int, i, rnd * 4096, rnd * 4096 + 1024) {
            forest_delete_int(&forest, Rand[i]);
        }
        forest_height(&forest, h[1]);

        // insert
        FOR (int, i, rnd * 4096 + 2048, rnd * 4096 + 4096) {
            forest_insert_int(&forest, Rand[i]);
        }
        forest_height(&forest, h[2]);

        forest_destroy(&forest);

        FOR (int, i, 0, 3) {
            FOR (int, j, 0, 3) {
                mx[i][j] = max(mx[i][j], h[i][j]);
                mn[i][j] = min(mn[i][j], h[i][j]);
                avg[i][j] += h[i][j];
            }
        }
    }

    char* label[] = {"after first insertion", "after removal",
                     "after 2nd insertion"};
    char* name[] = {"bst", "avl", "rb"};
    FOR (int, i, 0, 3) {
        printf("%s\n", label[i]);
        FOR (int, j, 0, 3) {
            printf("%s %d %d %d\n", name[j], mx[i][j], mn[i][j],
                   avg[i][j] / 10000);
        }
    }

    return 0;
}
