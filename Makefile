## Makefile for chessgame ##

#variables#
cc     = gcc
CFLAGS = -Wall -std=c11
DEBUG  = -g -DDEBUG
LFLAGS = -Wall $(DEBUG)

#targets
all: ChessGame

clean:  
	rm -f *.o
	rm -f ChessGame

#compilation files#


chessboard.o: chessboard.c boardConstants.h 
	$(cc) $(CFLAGS) -c chessboard.c -o chessboard.o

pieces.o: pieces.c boardConstants.h
	$(cc) $(CFLAGS) -c pieces.c -o pieces.o

king.o: king.c king.h boardConstants.h
	$(cc) $(CFLAGS) -c king.c -o king.o

queen.o: queen.c queen.h boardConstants.h
	$(cc) $(CFLAGS) -c queen.c -o queen.o

bishop.o: bishop.c bishop.h boardConstants.h
	$(cc) $(CFLAGS) -c bishop.c -o bishop.o

knight.o: knight.c knight.h boardConstants.h
	$(cc) $(CFLAGS) -c knight.c -o knight.o

rook.o: rook.c rook.h boardConstants.h
	$(cc) $(CFLAGS) -c rook.c -o rook.o

pawn.o: pawn.c pawn.h boardConstants.h
	$(cc) $(CFLAGS) -c pawn.c -o pawn.o

mainMethod.o: mainMethod.c boardConstants.h king.h queen.h bishop.h knight.h rook.h pawn.h
	$(cc) $(CFLAGS) -c mainMethod.c -o mainMethod.o

#executable file#
ChessGame: chessboard.o pieces.o king.o queen.o bishop.o knight.o rook.o pawn.o mainMethod.o
	$(cc) $(LFLAGS) mainMethod.o chessboard.o pieces.o  king.o queen.o bishop.o knight.o rook.o pawn.o -o ChessGame
