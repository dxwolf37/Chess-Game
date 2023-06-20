#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "boardConstants.h"

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

void DeleteChessBoard(CHESSB c){
        for(int y=0;y<8;y++){
                for(int x=0;x<8;x++){
                        if(c[x][y]){
                                DeleteChessBoardPiece(c,x,y);
                        }
                }
        }
}

void DisplayChessBoardWhite(CHESSB c){
    char ColorDisplay[2]={'W','B'};
    char CharacDisplay[6]={'P','R','N','B','K','Q'};
    for(int y=7;y>-1;y--){
                for(int x=0;x<8;x++){
                        if(x==0){
                        printf("  ");
                        for(int i=0;i<8;i++){
                                printf("+----");
                            }
                            printf("+\n %d",y+1);
                        }


                        printf("|");
                        if(!c[x][y]){
                            printf("    ");
                        }
                        else{
                            printf(" %c",ColorDisplay[c[x][y]->Color]);
                            printf("%c ",CharacDisplay[c[x][y]->Charac]);
                        }


                        if(x==7){
                            printf("|\n");
                            if(y==0){
                                printf("  ");
                                for(int i=0;i<8;i++){
                                printf("+----");
                                }
                                printf("+\n  ");
                                for(int i=0;i<8;i++){
                                printf("   %c ",65+i);
                                }
                                printf("\n");
                                }
                        }


                    }
                }
    }

void DisplayChessBoardBlack(CHESSB c){
    char ColorDisplay[2]={'W','B'};
    char CharacDisplay[6]={'P','R','N','B','K','Q'};
    for(int y=0;y<8;y++){
                for(int x=0;x<8;x++){
                        if(x==0){
                        printf("  ");
                        for(int i=0;i<8;i++){
                                printf("+----");
                            }
                            printf("+\n %d",y+1);
                        }


                        printf("|");
                        if(!c[x][y]){
                            printf("    ");
                        }
                        else{
                            printf(" %c",ColorDisplay[c[x][y]->Color]);
                            printf("%c ",CharacDisplay[c[x][y]->Charac]);
                        }


                        if(x==7){
                            printf("|\n");
                            if(y==7){
                                printf("  ");
                                for(int i=0;i<8;i++){
                                printf("+----");
                                }
                                printf("+\n  ");
                                for(int i=0;i<8;i++){
                                printf("   %c ",65+i);
                                }
                                printf("\n");
                                }
                        }


                    }
                }
    }
