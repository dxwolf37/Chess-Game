#ifndef CB8x8_H
#define CB8x8_H

static int turn;

struct Piece{
    int Color;
    int Charac;
};

typedef struct Piece PIECE;

typedef PIECE *CHESSB[8][8];

PIECE *NewPiece(int Color, int Charac);

void PrintPiece(PIECE *p);

void DeletePiece(PIECE *p);

void PrintChessBoard(CHESSB c);

void EmptyChessBoard(CHESSB c);

void DefaultChessBoard(CHESSB c);

void DeleteChessBoardPiece(CHESSB c, int x, int y);

void DeleteChessBoard(CHESSB c);

void MoveChessBoardPiece(CHESSB c, int x1, int y1, int x2, int y2);

//void DisplayChessBoard(CHESSB c);

void DisplayChessBoardWhite(CHESSB c);

void DisplayChessBoardBlack(CHESSB c);

#endif

