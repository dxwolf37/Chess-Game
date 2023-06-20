#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "boardConstants.h"
#include "queen.h"

void MoveQueen(CHESSB c, int x1, int y1, int x2, int y2) {
int x, y;
    // check if move is valid
        if (x1 != x2 && y1 != y2 && abs(x1-x2) != abs(y1-y2)) {
		printf("Invalid move. The Queen can only move diagonally, horizontally, or vertically.\n");
        	return;
    	} else if (x1 == x2) { // move vertical
		y = (y1 < y2) ? 1 : -1;
        	for (int i = y1 + y; i != y2; i += y) { // check column for pieces
            		if (c[x1][i]) {
                		printf("Invalid move. There are pieces in the way.\n");
                		return;
            		}
        	}		
    	} else if (y1 == y2) { // move horizontal
        	x = (x1 < x2) ? 1 : -1;
        	for (int i = x1 + x; i != x2; i += x) { // check row for pieces
            		if (c[i][y1]) {
                	printf("Invalid move. There are pieces in the way.\n");
                	return;
            		}
        	}
	} else { // check diagonal for pieces
        	x = (x1 < x2) ? 1 : -1;
        	y = (y1 < y2) ? 1 : -1;
        		for (int i = x1 + x, j = y1 + y; i != x2 && j != y2; i += x, j += y) {
            			if (c[i][j]) {
                			printf("Invalid move. There are pieces in the way.\n");
                			return;
            			}
        		}
    	}	
    // if the space is empty or is a different color, move
         if (!c[x2][y2] || c[x2][y2]->Color != c[x1][y1]->Color) {
                 // Move the Queen
                 turn = (turn == 0)?1:0;
                 MoveChessBoardPiece(c, x1, y1, x2, y2);
        }
}
