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