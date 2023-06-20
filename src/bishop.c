#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "boardConstants.h"
#include "bishop.h"

void MoveBishop(CHESSB c, int x1, int y1, int x2, int y2) {
    int x, y;
    // Check if the move is diagonal
    if (abs(x2 - x1) != abs(y2 - y1)) {
        printf("This is not a diagonal move.\n");
        return;
    }
    // Check each diagonal space between x1,y1, to x2,y2
    //If move is diagonal, check for obstacles and move the Bishop
    if (abs(x2 - x1) == abs(y2 - y1)) {
        x = (x1 < x2) ? 1 : -1;
        y = (y1 < y2) ? 1 : -1;
        // Check if there are any pieces in the way
        for (int i = x1 + x, j = y1 + y; i != x2 && j != y2; i += x, j += y) {
            if (c[i][j]) {
                printf("Invalid move. There are pieces in the way.\n");
                return;
            }
        }
    }
    if (!c[x2][y2] || c[x2][y2]->Color != c[x1][y1]->Color) {
        // Move the Bishop
        turn = (turn == 0) ? 1 : 0;
        MoveChessBoardPiece(c, x1, y1, x2, y2);
    }
}




