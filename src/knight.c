#include "boardConstants.h"
#include "knight.h"
#include <stdio.h>

void MoveKnight(CHESSB a, int x1, int y1, int x2, int y2){
	if((x1 > 7) || (y1 > 7) || (x1 < 0) || (y1 < 0)){
		printf("Out of Bounds!!");
	}
	else if((!a[x1][y1]) || (a[x1][y1]->Charac != 2)){
		printf("No piece/Selected Wrong Piece");
		
	}
	else{
		/* movement for up T and buttom */
		if(((x2 == x1 + 1) || (x2 == x1 - 1)) && ((y2 == y1 + 2) || (y2 == y1 - 2))){
			if(!a[x2][y2]){
				MoveChessBoardPiece(a,x1,y1,x2,y2);	
			}
			else if((a[x2][y2] -> Color) == (a[x1][x2] -> Color)){
				printf("pieces are the same color try new location.");
			}
			

			/*else{
				
			}*/
			
		}	
		/* movement  for left T and right  */
		else if(((x2 == x1 + 2) || (x2 == x1 - 2)) && ((y2 == y1 + 1) || (y2 == y1 - 1))){
			if(!a[x2][y2]){
				 MoveChessBoardPiece(a,x1,y1,x2,y2);
			}
			else if((a[x2][y2] -> Color) == (a[x1][x2] -> Color)){
                                printf("pieces are the same color try new location.");
			
			}
			/*else{
			
			}*/
					
		} 
	}
} 
