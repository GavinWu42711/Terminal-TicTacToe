//TicTacToe -- Gavin Wu, August 29 2026
#include <stdio.h>


//Prints out the rules to terminal
void printRules(void){
    printf("Welcome to Gavin's TicTacToe in C!\n");
    printf("To restart, enter Y\n");
    printf("To exit, enter N\n");
    printf("Player 1 has X. Player 2 has O\n");
    printf("Enter the respective number in the\nwhen it is your turn\n");
    printf("GLHF\n\n");
}

//Prints the board
void printBoard(char boardOutput[11][16]){
    for (int i = 0; i < 11; i++){
        printf("%s\n", (boardOutput)[i]);
    }
}

//Checks if a player has won and return which player
int checkBoard(char* (*board)[9]){

    int winningPlayer = 0;

    //Check rows
    for (int i = 0; i < 8; i += 3){
        if (*((*board)[i]) == *((*board)[i + 1]) && *((*board)[i]) == *((*board)[i + 2])){
            if(*((*board)[i]) == 'X'){
                winningPlayer = 1;
                break;
            }
            else{
                winningPlayer = 2;
                break;
            }
        }
    }
    if (!winningPlayer){
        //Check collumns
        for (int i = 0; i < 3; i++){
            if (*((*board)[i]) == *((*board)[i + 3]) && *((*board)[i]) == *((*board)[i + 6])){
                if(*((*board)[i]) == 'X'){
                    winningPlayer = 1;
                    break;
                }
                else{
                    winningPlayer = 2;
                    break;
                }
            }
        }
    }
    if (!winningPlayer){
        //Check the 2 diagonals
        if (*((*board)[0]) == *((*board)[4]) && *((*board)[0]) == *((*board)[8])){
            if(*((*board)[0]) == 'X'){
                winningPlayer = 1;
            }
            else{
                winningPlayer = 2;
            }
        }
        else if (*((*board)[2]) == *((*board)[4]) && *((*board)[2]) == *((*board)[6])){
            if(*((*board)[2]) == 'X'){
                winningPlayer = 1;
            }
            else{
                winningPlayer = 2;
            }
        }
    }

    return winningPlayer;
}

int main(void){

    //2D array representation of the TicTacToe board
    char boardOutput[11][16] = {"   #   #   ",
                                " 0 # 1 # 2 ",
                                "   #   #   ",
                                "###########",
                                "   #   #   ",
                                " 3 # 4 # 5 ",
                                "   #   #   ",
                                "###########",
                                "   #   #   ",
                                " 6 # 7 # 8 ",
                                "   #   #   ",};
    
    //Array of pointers containing the values on the board that will be modified and checked
    char *board[9] = {&boardOutput[1][1],&boardOutput[1][5],&boardOutput[1][9],
                      &boardOutput[5][1],&boardOutput[5][5],&boardOutput[5][9],
                      &boardOutput[9][1],&boardOutput[9][5],&boardOutput[9][9]};

    //Output the rules
    printRules();

    //Variable for if the player is playing
    int playing = 1;

    //Variable for which player is playing
    int player = 1;

    //Variable for which player won
    int winner = 0;

    //Main game loop
    do{

        //Print the current board
        printBoard(boardOutput);

        //Get user input
        char playerInput = ' ';
        printf("Please enter input: ");
        scanf(" %c", &playerInput);
        printf("\n");
        
        //Check what the user put in
        if (playerInput == 'y' || playerInput == 'Y'){
            //Reset board
            for (int i = 0; i < 9; i++){
                *(board[i]) = i + '0';
            }

            //Reset variables
            winner = 0;
            player = 1;
        }
        else if (playerInput == 'n' || playerInput == 'N'){
            //Stop playing
            playing = 0;
        }
        //Make sure no one has won yet
        else if (!winner){
            //Check if the player enterred a valid number
            int playerNumInput = playerInput - '0';
            if (playerNumInput >= 0 && playerNumInput <= 8){
                //Check if the number is square already taken or not
                if (*(board[playerNumInput]) == 'X' || *(board[playerNumInput]) == 'O'){
                    printf("Square already taken. Please choose another square\n");
                }
                else{
                    //Check which player's turn it is
                    if (player == 1){
                        *(board[playerNumInput]) = 'X';
                        player = 2;
                    }
                    else if (player == 2){
                        *(board[playerNumInput]) = 'O';
                        player = 1;
                    }
                    
                }
            }
            else{
                //Invalid input
                printf("Invalid input. Please enter Y, N, or a number from 0 - 8\n");
            }
        }

        //Check if a player has won
        winner = checkBoard(&board);
        if (winner == 1){
            printf("Player 1 won!\n");
        }
        else if (winner == 2){
            printf("Player 2 won!\n");
        }

    }while(playing);

    printf("\nThanks for trying my game!\n");

    return 0;
}