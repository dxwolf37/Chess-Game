#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "boardConstants.h"
#include "rook.h"

void MoveRook(CHESSB c, int x1, int y1, int x2, int y2) {
    // Check if the move is horizontal or vertical
    if (x1 != x2 && y1 != y2) {
        printf("Invalid move.\n");
        return;
    }
    int xAxis = 0;
    int yAxis = 0;
    if (x1 == x2) {
        yAxis = (y2 > y1) ? 1 : -1; // if y2 > y1 then 1, if false -1, moving vertically
    } else {
        xAxis = (x2 > x1) ? 1 : -1; // if x2 > x1 then 1, if false -1, moving horizontally
    }
    int x = x1 + xAxis;
    int y = y1 + yAxis;
    // while initial doesn't equal new position, check for obstructions
    while (x != x2 || y != y2) {
        if (c[x][y]) {
            printf("Invalid move. There are pieces in the way.\n");
            return;
        }
        x += xAxis;
        y += yAxis;
    }
    // Move the rook
    turn = (turn == 0)?1:0;
    MoveChessBoardPiece(c, x1, y1, x2, y2);

}


