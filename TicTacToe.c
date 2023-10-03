#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

    int turn = 1;
    char board[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool game_on = true, loop = true;
    char sign;

    int drawBoard();
    int game(int choose);
    int check();

int main(){
    int choose = 0;
    drawBoard();
    while (game_on == true){
        game(choose);
    }
    return 0;
}

int drawBoard(){
    system("cls");
    printf("\tTic Tac Toe\n");
    printf("\nPlayer 1(X)  -  Player 2(O)\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[1], board[2], board[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[4], board[5], board[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[7], board[8], board[9]);

    printf("     |     |     \n\n");

}


int game(int choose){
    if (turn % 2 == 0){
        printf("Player 2: ");
        scanf("%d", &choose);
        sign = 'O';
        if (board[choose] == 'O' || board[choose] == 'X' || choose < 1 || choose > 9){
            printf("Try again ");
        }
        else{
            board[choose] = sign;
            turn++;
            drawBoard();
        }
    }
    else{
        printf("Player 1: ");
        scanf("%d", &choose);
        sign = 'X';
        if (board[choose] == 'O' || board[choose] == 'X' || choose < 1 || choose > 9){
            printf("Try again ");
        }
        else{
            board[choose] = sign;
            turn++;
            drawBoard();
        }
        
    }
    check();
    return 0;
}

int check(){
    while (loop == true){
        for (int i = 1; i < 10; i +=3 ){
            if (board[i] == board[i+1] && board[i] == board[i+2]){
                game_on = false;
            }
        }
        for (int i = 1; i < 4; i++){
            if (board[i] == board[i+3] && board[i] == board[i+6]){
                game_on = false;
            }
        }
        if ( board[1] == board[5] && board[1] == board[9]){
            game_on = false;
        }
        if ( board[7] == board[5] && board[7] == board[3]){
            game_on = false;
        }
        loop = false;
    }
    loop = true;
    
    if (game_on == false && turn % 2 == 0){
        printf("Player 1 Won!");
    }
    else if (game_on == false){
        printf("Player 2 Won!");
    }
    return 0;
}