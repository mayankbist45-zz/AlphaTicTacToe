#include "ttt.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv) {
    init_boards();
    init_board(START_BOARD);
    join_graph(START_BOARD);
    compute_score();

    for (int i = 1; i < argc; i++) {
        int val = 0;
        for (int j = 0; j < strlen(argv[i]); j++) {
            val = val * 10 + argv[i][j] - '0';
        }
        print_node(htable[val]);
    }
}
