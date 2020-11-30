#include "ttt.h"
#include<string.h>

void init_boards() {
    for (int i = 0; i < HSIZE; i++) {
        htable[i].init = '0';
    }
}
int depth(const Board board) {
    int ct = 0;
    for (int i = 0; i < 9; i++)
        ct += (board[pos2idx[i]] == 'X' || board[pos2idx[i]] == 'O');
    return ct;
}

char winner(Board board) {
    for (int i = 0; i < 8; i++) {
        int a = pos2idx[WINS[i][0]], b = pos2idx[WINS[i][1]], c = pos2idx[WINS[i][2]];
        if (board[a] == board[b] && board[b] == board[c] && (board[a] == 'X' || board[a] == 'O'))return board[a];
    }
    if (depth(board) == 9)return '-';
    return '?';
}
char turn(Board board) {
    if (depth(board) == 9 || (winner(board) == 'X' || winner(board) == 'O'))return '-';
    int ctx = 0, cto = 0;
    for (int i = 0; i < 9; i++) {
        ctx += board[pos2idx[i]] == 'X';
        cto += board[pos2idx[i]] == 'O';
    }
    if (ctx == cto)return 'O';
    else return 'X';
}

void init_board(Board board) {
    int now = board_hash(board);
    htable[now].init = '1';
    htable[now].turn = turn(board);
    htable[now].depth = depth(board);
    strcpy(htable[now].board, board);
    htable[now].winner = winner(board);
}

void join_graph(Board board) {
    int now = board_hash(board);
    for (int i = 0; i < 9; i++) {
        if (board[pos2idx[i]] == 'X' || board[pos2idx[i]] == 'O')
            htable[now].move[i] = -1;
        else {
            Board temp;
            strcpy(temp, board);
            temp[pos2idx[i]] = turn(board);
            htable[now].move[i] = board_hash(temp);
            if (htable[board_hash(temp)].init == '0') {
                init_board(temp);
                join_graph(temp);
            }
        }
    }
}

int best_move(int board) {
    struct BoardNode *cur = &htable[board];
    char current_turn = turn(htable[board].board);
    int mx = -1, mn = (int) 1e9, id1 = -1, id2 = -1;
    for (int i = 0; i < 9; i++) {
        if (cur->move[i] == -1)continue;
        int temp = cur->move[i];
        if (mx < htable[temp].score) {
            id1 = i;
            mx = htable[temp].score;
        }
        if (mn > htable[temp].score) {
            id2 = i;
            mn = htable[temp].score;
        }
    }
    return current_turn == 'X' ? id1 : id2;
}
int getScore(struct BoardNode *cur) {
    char win = winner(cur->board);
    if (depth(cur->board) == 9 || win == '-')return 0;
    else if (win == 'X')return 1;
    else if (win == 'O')return -1;
    else {
        int id = best_move(board_hash(cur->board));
        if(id == -1)return 0;
        id = cur->move[id];
        id = htable[id].score;
        return id;
    }
}

void compute_score() {
    for (int depth = 9; depth >= 0; depth--) {
        for (int i = 0; i < HSIZE; i++) {
            if (htable[i].depth == depth) {
                htable[i].score = getScore(&htable[i]);
            }
        }
    }
}

