// Added Functions so far...
//PAWN
//ROOK
//QUEEN
//BISHOP
//KING
//CHECK
//EN PASSANT

// Checks if the initial spot and new spot are the same color. No move is allowed.
// Checks if the player chooses their color for initial piece
// Checks if the initial spot has a piece

/* int getNextTurn(int turn);
 *
 * int getNextTurn(int Turn){
 * return !turn;
 * }

 /* turn = getNextTurn(turn);*/

#include <stdlib.h>
#include <stdio.h>
//#include <string.h>
#include <assert.h>
#include <stdbool.h>
//#include "CB8x8.h"
int turn; // to make players change turns
int move;

struct Piece{
    int Color;
    int Charac;
};

typedef struct Piece PIECE;
typedef PIECE *CHESSB[8][8];

PIECE *NewPiece(int Color, int Charac){
    PIECE *p;
    p=malloc(sizeof(PIECE));
    if(!p){
        perror("Out of memory\n");
        exit(10);
    }
    p->Color=Color;
    p->Charac=Charac;
    return p;
}

void PrintPiece(PIECE *p){
    if(!p){
        printf("The piece is empty.\n");
    }
    else{
        char ColorList[2][10]={"White","Black"};
        char CharacterList[6][10]={"Pawn","Rook","Knight","Bishop","King","Queen"};
        printf("Pcolor is %s; ",ColorList[p->Color]);
        printf("Pcharac is %s.\n",CharacterList[p->Charac]);
    }
}


void DeletePiece(PIECE *p){
    assert(p);
    free(p);
}

void PrintChessBoard(CHESSB c){
    for(int y=0;y<8;y++){
        for(int x=0;x<8;x++){
            printf("At Position %d x %d: ",x,y);
            PrintPiece(c[x][y]);
        }
    }
}

void EmptyChessBoard(CHESSB c){
    for(int y=0;y<8;y++){
        for(int x=0;x<8;x++){
            c[x][y]=NULL;
        }
    }
}

void DeleteChessBoardPiece(CHESSB c, int x, int y){
    assert(c[x][y]);
    PIECE *p;
    p=c[x][y];
    c[x][y]=NULL;
    DeletePiece(p);
}

void DeleteChessBoard(CHESSB c){
    for(int y=0;y<8;y++){
        for(int x=0;x<8;x++){
            if(c[x][y]){
                DeleteChessBoardPiece(c,x,y);
            }
        }
    }
}

/*void MoveChessBoardPiece(CHESSB c, int x1, int y1, int x2, int y2){
    assert(c[x1][y1]);
    PIECE *p;
    p=c[x1][y1];
    c[x1][y1]=NULL;
    if(c[x2][y2]){
        DeleteChessBoardPiece(c,x2,y2);
    }
    c[x2][y2]=p;
}*/

void MoveChessBoardPiece(CHESSB c, int x1, int y1, int x2, int y2){
    assert(c[x1][y1]);
    PIECE *p;
    p=c[x1][y1];
    c[x1][y1]=NULL;
    if(c[x2][y2]){
        DeleteChessBoardPiece(c,x2,y2);
    }
    c[x2][y2]=p;
}

void DefaultChessBoard(CHESSB c){
    DeleteChessBoard(c);
    int ButtomNTop[8]={1,2,3,5,4,3,2,1};
    int ColorSide[8]={0,0,2,2,2,2,1,1};
    for(int y=0;y<8;y++){
        for(int x=0;x<8;x++){
            if(y>1&&y<6){
                continue;
            }
            else if(y==1){
                PIECE *p;
                p=NewPiece(0,0);
                c[x][y]=p;
            }
            else if(y==6){
                PIECE *p;
                p=NewPiece(1,0);
                c[x][y]=p;
            }
            else{
                PIECE *p;
                p=NewPiece(ColorSide[y],ButtomNTop[x]);
                c[x][y]=p;
            }

        }
    }
}

void MovePawn(CHESSB c, int x1, int y1, int x2, int y2){
    PIECE *p = c[x1][y1];
    PIECE *p2 = c[x2][y2];

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
    // while x and y doesn't equal new position, check for obstructions
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
    // if the space is empty or is a different color, move
    if (!c[x2][y2] || c[x2][y2]->Color != c[x1][y1]->Color) {
        // Move the Bishop
        turn = (turn == 0) ? 1 : 0;
        MoveChessBoardPiece(c, x1, y1, x2, y2);
    }
}

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

void MoveKing(CHESSB c, int x1, int y1, int x2, int y2) {
    //assert(c[x1][y1]); // check if the source position has a piece
    //PIECE *p = c[x1][y1];

    // check if the move is legal
    if (!((abs(x2 - x1) == 1 && abs(y2 - y1) == 0) || (abs(x2 - x1) == 0 && abs(y2 - y1) == 1) || (abs(x2 - x1) == 1 && abs(y2 - y1) == 1))) {
        printf("Invalid Move.\n");
        return;
    } else if (!c[x2][y2] || c[x2][y2]->Color != c[x1][y1]->Color) {
        // Move the King
        turn = (turn == 0)?1:0;
        MoveChessBoardPiece(c, x1, y1, x2, y2);
    }
}

void isKingChecked(CHESSB c) {
    int kingX, kingY;
    //PIECE *king;
    int otherTeamColor = turn == 0 ? 1 : 0;
    // find location of king of current color
    // check all spots, if found break
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            PIECE *p = c[x][y];
            // if the king is found set the position to kingX and kingY
            if (p && p->Charac == 4 && p->Color == turn) {
                kingX = x;
                kingY = y;
                //king = p;
                break;
            }
        }
    }
    // check if any opposing piece can capture the king
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            PIECE *p = c[x][y];
            if (p && p->Color == otherTeamColor) {
                // check if piece has a valid move to king's square
                switch (p->Charac) {
                    case 0:  // pawn
                        if ((p->Color == 0 && x == kingX - 1 && y == kingY - 1) || (p->Color == 0 && x == kingX + 1 && y == kingY - 1) ||
                            (p->Color == 1 && x == kingX - 1 && y == kingY + 1) || (p->Color == 1 && x == kingX + 1 && y == kingY + 1)) {
                            printf("The king is checked! Move the king or another piece to get out of check!");
                            return;
                        }
                    case 1:  // rook
                        if (x == kingX || y == kingY) {
                            int xAxis = x > kingX ? -1 : 1; //move x direction
                            int yAxis = y > kingY ? -1 : 1; //move y direction
                            int i = x + xAxis;
                            int j = y + yAxis;
                            while (i != kingX || j != kingY) { //check for pieces in the way
                                if (c[i][j]) {
                                    break;
                                }
                                i += xAxis;
                                j += yAxis;
                            }
                            if (i == kingX && j == kingY) { // if there's no pieces
                                printf("The king is checked! Move the king or another piece to get out of check!");
                                return;
                            }
                        }
                    case 2:  // knight
                        if ((abs(x - kingX) == 2 && abs(y - kingY) == 1) ||
                            (abs(x - kingX) == 1 && abs(y - kingY) == 2)) {
                            printf("The king is checked! Move the king or another piece to get out of check!");
                            return;
                        }
                    case 3:  // bishop
                        if (abs(x - kingX) == abs(y - kingY)) {
                            int xAxis = x > kingX ? -1 : 1;
                            int yAxis = y > kingY ? -1 : 1;
                            int i = x + xAxis;
                            int j = y + yAxis;
                            //check for pieces in the way
                            while (i != kingX && j != kingY) {
                                if (c[i][j]) {
                                    break;
                                }
                                i += xAxis;
                                j += yAxis;
                            }
                            if (i == kingX && j == kingY) {
                                printf("The king is checked! Move the king or another piece to get out of check!");
                                return;
                            }
                        }
                    case 4:  // king
                        if ((abs(x - kingX) <= 1 && abs(y - kingY) <= 1) && !(x == kingX && y == kingY)) {
                            printf("The king is checked! Move the king or another piece to get out of check!");
                            return;
                        }
                    case 5:  // queen
                        if (x == kingX || y == kingY || abs(x - kingX) == abs(y - kingY)) { //check horizontal, vertical, diagonal
                            if (x == kingX || y == kingY) { // horizontal/vertical
                                int xAxis = x > kingX ? -1 : 1;
                                int yAxis = y > kingY ? -1 : 1;
                                int i = x + xAxis;
                                int j = y + yAxis;
                                while (i != kingX || j != kingY) {
                                    if (c[i][j]) {
                                        break;
                                    }
                                    i += xAxis;
                                    j += yAxis;
                                }
                                if (i == kingX && j == kingY) {
                                    printf("The king is checked! Move the king or another piece to get out of check!");
                                    return;
                                }
                            } else { // diagonal
                                int xAxis = x > kingX ? -1 : 1;
                                int yAxis = y > kingX ? -1 : 1;
                                int i = x + xAxis;
                                int j = y + yAxis;
                                while (i != kingX && j != kingY) {
                                    if (c[i][j]) {
                                        break;
                                    }
                                    i += xAxis;
                                    j += yAxis;
                                }
                                if (i == kingX && j == kingY) {
                                    printf("The king is checked! Move the king or another piece to get out of check!");
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

int main()
{

    CHESSB c;
    EmptyChessBoard(c);

    DefaultChessBoard(c);

    PrintChessBoard(c);

    int x1, y1, x2, y2;
    while (1) {
        //checks if the move is within the board and if there's a piece at x1,y1
        //if the input is not 2 characters or is not within bounds or there's no piece at the input, then
        //give an error message, clear the input, and re loop
        printf("Enter your piece location (x1,y1): ");
        if (scanf("%d,%d", &x1, &y1) != 2 || x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || !c[x1][y1]) {
            printf("Please try again. Position not found.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        //checks to see if the user chooses the right color
        //if (c[x1][y1] && c[x1][y1]->Color == !turn)
        if (c[x1][y1] && c[x1][y1]->Color != turn){
            printf("Wrong color chosen.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        //if the color is correct, ask for the new position x2,y2
        //same condition as x1,y1 + if there's a piece at x2,y2 we need to check its color
        //if the color is the same ask user for a new move, if the color is different allow move (capture)
        if (c[x1][y1] && c[x1][y1]->Color == turn) {
            printf("Enter where you want to move the piece (x2,y2): ");
            if (scanf("%d,%d", &x2, &y2) != 2 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7 ||
                (c[x2][y2] && c[x1][y1]->Color == c[x2][y2]->Color)) {
                printf("Please try again. Position not found.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
        }

        PIECE *p = c[x1][y1];
        if (p->Charac == 0){
            MovePawn(c, x1, y1,x2, y2);
            isKingChecked(c);
        } else if (p->Charac == 1){
            MoveRook(c, x1, y1,x2, y2);
            isKingChecked(c);
        } else if (p->Charac == 3){
            MoveBishop(c, x1, y1,x2, y2);
            isKingChecked(c);
        } else if (p->Charac == 4){
            MoveKing(c, x1, y1, x2, y2);
            isKingChecked(c);
        } else if (p->Charac == 5){
            MoveQueen(c, x1, y1,x2, y2);
            isKingChecked(c);
        }
        printf("\n");
        PrintChessBoard(c);

    }

    //DeleteChessBoard(c);

    // return 0;
}

