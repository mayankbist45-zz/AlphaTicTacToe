#include "ttt.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv) {
    char human;

    init_boards();
    init_board(START_BOARD);
    join_graph(START_BOARD);

    int ct = 0;
    for(int i = 0; i < HSIZE; i++)
        ct += htable[i].init == '1';
    printf("The total number of nodes with init = '1' : %d\n", ct);
}
