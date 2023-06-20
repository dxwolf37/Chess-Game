#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "boardConstants.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"


//display main menu and prompt user for choice of side
int main()
{

	CHESSB c;

        EmptyChessBoard(c);

        DefaultChessBoard(c);

        DisplayChessBoardWhite(c);
                                        //DisplayChessBoardBlack(c);
                                        //

	printf("\nWelcome to ChessGPT! The world's smartest and funniest chess program!\n\n");
	
	//prototypes
	
	//void mainMenu();


	//calls mainMenu
	//mainMenu();
	
	//***Function***
	
	//mainMenu function
	//int mainMenu()
	{
		int choice;
		//do while loop that presents menu until exit of application
		do {
			printf("Please make a selection from the main menu below.\n\n");
			printf("1. Start a game!\n");
			printf("2. Tell a joke.\n");
			printf("3. Exit program :( \n");
			
			scanf(" %d", &choice);
			
			//validate input and start game if input is 1
			if (choice == 1)
			{
				int playerSide;
				printf("\nGreat choice! Please select your preferences for the color ");
				printf("of your pieces.\n");
				printf("Input 1 for white pieces or 2 for black pieces. White pieces move first.\n");				     
				
				scanf(" %d", &playerSide);

				//case statemetns for playerSide, assign player to board side
				if (playerSide == 1)
				{
        				//DisplayChessBoardBlack(c);

					int x1, y1, x2, y2;
    					while (1) {
        					//checks if the move is within the board and if there's a piece at x1,y1
        					//        //if the input is not 2 characters or is not within bounds or there's no piece at the input, then
        					//                //give an error message, clear the input, and re loop
						printf("Enter your piece location (x1,y1): ");
						if (scanf("%d,%d", &x1, &y1) != 2 || x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || !c[x1][y1]) {
							printf("Please try again. Position not found.\n");
            						while (getchar() != '\n'); // Clear input buffer
           						continue;
						}

						//checks to see if the user chooses the right color
						if (c[x1][y1] && c[x1][y1]->Color == !turn){
							printf("Wrong color chosen.\n");
							while (getchar() != '\n'); // Clear input buffer
            						continue;
						}

						//if the color is correct, ask for the new position x2,y2
						//        //same condition as x1,y1 + if there's a piece at x2,y2 we need to check its color
						//                //if the color is the same ask user for a new move, if the color is different allow move (capture)
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
        					DisplayChessBoardWhite(c);
        					//DisplayChessBoardBlack(c);
            				}
        
                		//DeleteChessBoard(c);
        
                    		// return 0;
				}	
				
				else if (playerSide == 2)
				{
					DisplayChessBoardBlack(c);
					//moveGTP();
				}

				else 
				{
					printf("\nOops! That is not a valid selection. Please enter a 1 or 2.\n\n");
					scanf(" %d", &playerSide);
				}
				
			
				//initialize board, display to user
			
 				//ask user for their move
		
				//check if game ends


			}
			
			else if (choice == 2)
			{
				printf("Knock knock!\n");
				printf("Who's there?\n");
				printf("Your mom!\n");
				printf("Ok go play some chess now.\n");
			}

			else if (choice == 3)
			{

				printf("Thanks for playing! Have a great day!\n");
				printf("Exiting program.\n");
		   	}

			else
			{
				printf("\nYou have selected a wrong number. You will be returned to the main ");
				printf("menu.\n");
				
			}
		} while (choice != 3);
		return 1;

	}

	return 0;	

}


