#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "boardConstants.h"
#include "pawn.h"

void MovePawn(CHESSB c, int x1, int y1, int x2, int y2){
    PIECE *p = c[x1][y1];
    PIECE *p2 = c[x2][y2];

    int move;

    // check if pawn is moving forward, check if color is white, check if square in front is open
    if(p->Charac == 0 && p->Color == 0 && x2 == x1 && y2 == y1+1 && !p2){
        turn = (turn == 0)?1:0; // change turn
        move = 1;
        MoveChessBoardPiece(c, x1, y1, x2, y2);
    }
        // same conditions, but for black piece
    else if(p->Charac == 0 && p->Color == 1 && x2 == x1 && y2 == y1-1 && !p2){
        turn = (turn == 0)?1:0;
        move = 1;
        MoveChessBoardPiece(c, x1, y1, x2, y2);
    }
        // check if pawn is moving two squares forward on its first move
        // check if initial location is at y = 1 b/c it's the starting column, check if y2 = 3 b/ that's 2 spaces forward
        // and check if the space between initial and final is open
    else if(p->Charac == 0 && p->Color == 0 && y1 == 1 && y2 == 3 && x1 == x2 && !p2 && !c[x1][y1+1]){
        turn = (turn == 0)?1:0;
        move = 2;
        MoveChessBoardPiece(c, x1, y1, x2, y2);
    }
        // same, but for black
    else if(p->Charac == 0 && p->Color == 1 && y1 == 6 && y2 == 4 && x1 == x2 && !p2 && !c[x1][y1-1]){
        turn = (turn == 0)?1:0;
        move = 2;
        MoveChessBoardPiece(c, x1, y1, x2, y2);
    }
        // check if pawn is attacking
        // RightDown, LeftDown, RightUp, LeftUp
        //input of x2, y2 checks if x1, y1 are the same color
    else if(p2 && ((p->Color == 0 && x2 == x1+1 && y2 == y1+1) || (p->Color == 0 && x2 == x1-1 && y2 == y1+1) || (p->Color == 1 && x2 == x1+1 && y2 == y1-1) || (p->Color == 1 && x2 == x1-1 && y2 == y1-1))){
        turn = (turn == 0)?1:0;
        move = 1;
        MoveChessBoardPiece(c, x1, y1, x2, y2);
    }
    else if(move == 2 && c[x2][y2] == NULL && p->Charac == 0 && x1 != x2) { //if the spot is empty, piece moving is a pawn, and it's a diagonal move
        int enPassantYAxis = (p->Color == 0) ? 4 : 3; //set YAxis for enPassant piece
        PIECE *enPassantp = c[x2][enPassantYAxis];
        //if the enPassantp piece exists and the enPassant piece and capture piece are different color...
        // and the capture piece is a pawn
        if(enPassantp && enPassantp->Color != p->Color && enPassantp->Charac == 0) {// en passant and pawn can capture
            MoveChessBoardPiece(c, x1, y1, x2, y2);
            c[x2][enPassantYAxis] = NULL;
        }
    }
    else{
        printf("Invalid move.\n");
    }
}
