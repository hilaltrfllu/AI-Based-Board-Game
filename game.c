#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define SIZE 49
enum {X,O,_};
//int user = 1;
//int comp = 2;
int user = 0;
int comp = 1;
int currentPlayer;
int board[SIZE];
char movement[1];
char piece[1];
time_t t;
int count=1;
int i,j,k;
char input[1]; //character array for coordinate transposition
int turn=0;
int n_pieces_user; //number of pieces for user
int n_pieces_comp; //number of pieces for computer
int n_pieces_sum=0;
//n_pieces_sum = n_pieces_user + n_pieces_comp;
int arr_pos[];
int arr_pos_user[];
int arr_pos_comp[];


int convert_str_to_int(char input[1]){
    int int_input=0;
    if(strcmp(input,"a1")==0){int_input=1;}else if(strcmp(input,"a2")==0){int_input=2;}else if(strcmp(input,"a3")==0){int_input=3;}else if(strcmp(input,"a4")==0){int_input=4;}else if(strcmp(input,"a5")==0){int_input=5;}else if(strcmp(input,"a6")==0){int_input=6;}else if(strcmp(input,"a7")==0){int_input=7;}
    else if(strcmp(input,"b1")==0){int_input=8;}else if(strcmp(input,"b2")==0){int_input=9;}else if(strcmp(input,"b3")==0){int_input=10;}else if(strcmp(input,"b4")==0){int_input=11;}else if(strcmp(input,"b5")==0){int_input=12;}else if(strcmp(input,"b6")==0){int_input=13;}else if(strcmp(input,"b7")==0){int_input=14;}
    else if(strcmp(input,"c1")==0){int_input=15;}else if(strcmp(input,"c2")==0){int_input=16;}else if(strcmp(input,"c3")==0){int_input=17;}else if(strcmp(input,"c4")==0){int_input=18;}else if(strcmp(input,"c5")==0){int_input=19;}else if(strcmp(input,"c6")==0){int_input=20;}else if(strcmp(input,"c7")==0){int_input=21;}
    else if(strcmp(input,"d1")==0){int_input=22;}else if(strcmp(input,"d2")==0){int_input=23;}else if(strcmp(input,"d3")==0){int_input=24;}else if(strcmp(input,"d4")==0){int_input=25;}else if(strcmp(input,"d5")==0){int_input=26;}else if(strcmp(input,"d6")==0){int_input=27;}else if(strcmp(input,"d7")==0){int_input=28;}
    else if(strcmp(input,"e1")==0){int_input=29;}else if(strcmp(input,"e2")==0){int_input=30;}else if(strcmp(input,"e3")==0){int_input=31;}else if(strcmp(input,"e4")==0){int_input=32;}else if(strcmp(input,"e5")==0){int_input=33;}else if(strcmp(input,"e6")==0){int_input=34;}else if(strcmp(input,"e7")==0){int_input=35;}
    else if(strcmp(input,"f1")==0){int_input=36;}else if(strcmp(input,"f2")==0){int_input=37;}else if(strcmp(input,"f3")==0){int_input=38;}else if(strcmp(input,"f4")==0){int_input=39;}else if(strcmp(input,"f5")==0){int_input=40;}else if(strcmp(input,"f6")==0){int_input=41;}else if(strcmp(input,"f7")==0){int_input=42;}
    else if(strcmp(input,"g1")==0){int_input=43;}else if(strcmp(input,"g2")==0){int_input=44;}else if(strcmp(input,"g3")==0){int_input=45;}else if(strcmp(input,"g4")==0){int_input=46;}else if(strcmp(input,"g5")==0){int_input=47;}else if(strcmp(input,"g6")==0){int_input=48;}else if(strcmp(input,"g7")==0){int_input=49;}
    return int_input;
}

bool isValid_Input(char input[1]){
    if(strcmp(input,"a1")==0 || strcmp(input,"a2")==0 || strcmp(input,"a3")==0 || strcmp(input,"a4")==0 || strcmp(input,"a5")==0 || strcmp(input,"a6")==0 || strcmp(input,"a7")==0
    || strcmp(input,"b1")==0 || strcmp(input,"b2")==0 || strcmp(input,"b3")==0 || strcmp(input,"b4")==0 || strcmp(input,"b5")==0 || strcmp(input,"b6")==0 || strcmp(input,"b7")==0
    || strcmp(input,"c1")==0 || strcmp(input,"c2")==0 || strcmp(input,"c3")==0 || strcmp(input,"c4")==0 || strcmp(input,"c5")==0 || strcmp(input,"c6")==0 || strcmp(input,"c7")==0
    || strcmp(input,"d1")==0 || strcmp(input,"d2")==0 || strcmp(input,"d3")==0 || strcmp(input,"d4")==0 || strcmp(input,"d5")==0 || strcmp(input,"d6")==0 || strcmp(input,"d7")==0
    || strcmp(input,"e1")==0 || strcmp(input,"e2")==0 || strcmp(input,"e3")==0 || strcmp(input,"e4")==0 || strcmp(input,"e5")==0 || strcmp(input,"e6")==0 || strcmp(input,"e7")==0
    || strcmp(input,"f1")==0 || strcmp(input,"f2")==0 || strcmp(input,"f3")==0 || strcmp(input,"f4")==0 || strcmp(input,"f5")==0 || strcmp(input,"f6")==0 || strcmp(input,"f7")==0
    || strcmp(input,"g1")==0 || strcmp(input,"g2")==0 || strcmp(input,"g3")==0 || strcmp(input,"g4")==0 || strcmp(input,"g5")==0 || strcmp(input,"g6")==0 || strcmp(input,"g7")==0){
           return true;
    }
    else
        return false;
}

int isValid_Position(){
     if((((convert_str_to_int(piece)-1-7) - (convert_str_to_int(movement)-1)) == 0)
        || (((convert_str_to_int(piece)-1-1) - (convert_str_to_int(movement)-1)) == 0)
        || (((convert_str_to_int(piece)-1+1) - (convert_str_to_int(movement)-1)) == 0)
        || (((convert_str_to_int(piece)-1+7) - (convert_str_to_int(movement)-1)) == 0)){
            return 1;
    }else
        return 0;
}

// initialize the board with empty cells
void initBoard(int board[]) {
	for(i=0; i<SIZE; i++)
		board[i] = _;
}

void randBoard(int board[]){
    int chosen_player;
    int position;
    //int n_pieces_user,n_pieces_comp;
    printf("Input number of pieces for user and computer respectively: ");
    scanf("%d %d", &n_pieces_user, &n_pieces_comp);
    n_pieces_sum = n_pieces_user + n_pieces_comp;
    //int arr_pos_user[n_pieces_user],arr_pos_comp[n_pieces_comp];
    printf("Press 1 to choose Player1, press 2 to Player2 (Player1 plays first!): ");
    srand((unsigned)time(&t)); //initializes random number generator
    while(1){
        scanf("%d",&chosen_player);
        if(chosen_player == 1){ //User plays first
            turn = user;
            user=0;
            comp=1;
            for(i=0; i<n_pieces_sum; i++){
                position = rand()%SIZE;
                for(k=0; k<i; k++){
                    while((board[position] == 0) || (board[position] == 1)){
                        position = rand()%SIZE;
                        arr_pos[i] = position;
                    }
                    arr_pos[i] = position;
                }
                if(i<n_pieces_user){
                    arr_pos_user[i] = position;
                    arr_pos[i] = position;
                    printf("\nUser's random initial piece position: %d", arr_pos[i]);
                    board[position] = 0;
                }
                if(i>=n_pieces_user && i<n_pieces_sum){
                    arr_pos_comp[i] = position;
                    arr_pos[i] = position;
                    printf("\nComputer's random initial piece position: %d", arr_pos[i]);
                    board[position] = 1;
                }
            }
            break;
        }
        else if(chosen_player == 2){ //Computer plays first
            turn = comp;
            user=1;
            comp=0;
            for(i=0; i<n_pieces_sum; i++){
                position = rand()%SIZE;
                for(k=0; k<i; k++){
                    while((board[position]==0) || (board[position]==1)){
                        position = rand()%SIZE;
                        arr_pos[i] = position;
                    }
                    arr_pos[i] = position;
                }
                if(i<n_pieces_comp){
                    arr_pos_comp[i] = position;
                    arr_pos[i] = position;
                    printf("\nComputer's random initial piece position: %d", arr_pos[i]);
                    board[position] = 0;
                }
                if(i>=n_pieces_comp && i<n_pieces_sum){
                    arr_pos_user[i] = position;
                    arr_pos[i] = position;
                    printf("\nUser's random initial piece position: %d", arr_pos[i]);
                    board[position] = 1;
                }
            }
            break;
        }else
            printf("Choose correct input!\n");
    }
    printf("\n");
}
void printBoard(const int board[]){
    char symbol[] = { 'X','O','_' };
    //char symbol[] = { '_','X','O' };
	printf("\n              BOARD\n\n");
	for(i=0; i<SIZE; i++) {
		if(i != 0 && i%7 == 0)
			printf("\n\n");
		printf("  %c  ",symbol[board[i]]);
	}
	printf("\n\n");
}

//check if the board is full or has empty cell
bool isBoardFull(const int board[]){
    for(i=0; i<SIZE; i++)
        if(board[i] == _)
            return false;

    return true;
}

void makeMove(int board[], const int cell, const int turn){
    board[cell] = turn;
    board[convert_str_to_int(piece)-1] = _;
}

//returns which move gives the maximum score
int max(int *scoreList, int moveCount, int *moveList, int *bestMove){
    if(!moveCount)
        return 0;
    int max = -20;
    for(i=0; i<moveCount; i++){
        if(scoreList[i] > max){
            max = scoreList[i];
            *bestMove = moveList[i];
        }
    }
    return max;
}

//returns which move gives the minimum score
int min(int *scoreList, int moveCount, int *moveList, int *bestMove){
    if(!moveCount)
        return 0;
    int min = +20;
    for(i=0; i<moveCount; i++){
        if(scoreList[i] < min){
            min = scoreList[i];
            *bestMove = moveList[i];
        }
    }
    return min;
}
int checkUser(const int board[], const int turn){
    for(i=0; i<n_pieces_user; i++){
        if(board[arr_pos_user[i]-7] != _ ||
            board[arr_pos_user[i]-1] != _ ||
            board[arr_pos_user[i]+1] != _ ||
            board[arr_pos_user[i]+7] != _ )
            return 1;
    }
    return 0;
}
int checkComp(const int board[], const int turn){
    for(i=0; i<SIZE; i++){
        if(board[arr_pos_comp[i]-7] != _ ||
            board[arr_pos_comp[i]-1] != _ ||
            board[arr_pos_comp[i]+1] != _ ||
            board[arr_pos_comp[i]+7] != _ )
            return 1;
    }
    return 0;
}

int getScore(const int board[], const int turn){
	if(checkComp(board,turn))
		return 10;
	if(checkComp(board,!turn))
		return -10;
	return 0;
}

int minmax(int board[],int turn, int *depth){
    int moveList[SIZE];
    int moveCount=0;
    int bestMove;
    int scoreList[SIZE];
    int bestScore;

    bestScore = getScore(board,comp);
    if(bestScore)
        return bestScore - *depth;

    //fill the moveList[]
    for(i=0; i<n_pieces_comp; i++){
       // if(board[i] == _)
           // moveList[moveCount++] = i;
        if(board[arr_pos_comp[i]-7] == _)
            moveList[moveCount++] == board[arr_pos_comp[i]-7];
        if(board[arr_pos_comp[i]-1] == _)
            moveList[moveCount++] == board[arr_pos_comp[i]-1];
        if(board[arr_pos_comp[i]+1] == _)
            moveList[moveCount++] == board[arr_pos_comp[i]+1];
        if(board[arr_pos_comp[i]+7] == _)
            moveList[moveCount++] == board[arr_pos_comp[i]+7];
    }

    //loop through all moves
    int move;
    for(i=0; i<moveCount; i++){
        move = moveList[i];
        makeMove(board,move,turn);
        (*depth)++;
        scoreList[i] = minmax(board,!turn,depth);
        (*depth)--;

        makeMove(board,move,_);
    }
    if(turn == user){
        //MIN
        bestScore = min(scoreList,moveCount,moveList,&bestMove);
    }
    if(turn == comp){
        //MAX
        bestScore = max(scoreList,moveCount,moveList,&bestMove);
    }
    if(*depth != 0)
        return bestScore;
    else
        return bestMove;

}

int find_moveable(int *board,int turn){
    int count_moveable=0;
    int moveable[SIZE];
    for(i=0; i<SIZE; i++){
        if(board[arr_pos_comp[i]-7] == _)
            count_moveable++;
            moveable[count_moveable]=board[arr_pos_comp[i]-7];
        if(board[arr_pos_comp[i]-1] == _)
            count_moveable++;
            moveable[count_moveable]=board[arr_pos_comp[i]-1];
        if(board[arr_pos_comp[i]+1] == _)
            count_moveable++;
            moveable[count_moveable]=board[arr_pos_comp[i]+1];
        if(board[arr_pos_comp[i]+7] == _)
            count_moveable++;
            moveable[count_moveable]=board[arr_pos_comp[i]+7];
    }
    return count_moveable;
}

int comp_move(int *board,int turn) {
    int depth = 0;
    int bestMove = minmax(board,turn,&depth); //KONTROL ET
    printf("-Computer: Best position to move: %d\n",bestMove+1);
    return bestMove;
}

int user_move(const int *board){
    printf("\nChoose piece to move: ");
    scanf("%s", piece);
    while(isValid_Input(piece) == false){
        printf("\nInvalid input. Choose piece to move again: ");
        scanf("%s", piece);
    }
    printf("\n");
    int move;
    if((board[convert_str_to_int(piece)-1] != _) && (board[convert_str_to_int(piece)-1] != O)){
        while(1) {
            printf("\nChoose the new position for %s: ",piece);
            scanf("%s", movement);
            while(isValid_Input(movement) == false){
                printf("\nInvalid input. Choose the new position for %s again: ",piece);
                scanf("%s", movement);
            }
            while(isValid_Position() == 0){
                printf("\nInvalid input2. Choose the new position for %s again: ",piece);
                scanf("%s", movement);
            }
            printf("\nPlayer moves the piece at %s to %s", piece, movement); ///PIECE YI SEÇ, MOVEMENT POSITIONINA TAŞI
            printf("\n");
            move = convert_str_to_int(movement);
            if((board[move-1]==_) && (move>=0) && (move<=49))
                break;
            else{
                printf("\nThis is not a valid position!");
            }
        }
    }else{
       user_move(board);
    }
	return move-1;
}


void run(){
    int turn_limit_user=0;
    int turn_limit_comp=0;

    printf("Input a turn limit for user and computer respectively: ");
    scanf("%d %d",&turn_limit_user, &turn_limit_comp);

    bool game_over = false;
    int move;

    initBoard(board);
    randBoard(board);
    printBoard(board);

    while(game_over == false){
        //WHEN IT REACHES TO THE TURN LIMIT, GAME OVER
        if((turn_limit_user<0)){ //USER WIN
            /*if(checkUser(board,turn)){
                printf("GAME OVER! ");
                game_over = true;
                printf("COMPUTER WON\n");
            }*/
            game_over = true;
            printf("Reached the turn limit of the user. ");
            printf("COMPUTER WON\n");
        }else{
            if(find_moveable(board,turn)>0){
                if(turn == user){
                    move = user_move(board);
                    makeMove(board,move,turn);
                    turn_limit_user--;
                    printBoard(board);
                    find_moveable(board,turn);
                    //turn = user;
                }
            }else if(find_moveable(board,turn)==0){
                printf("DO NOT FIND MOVEABLE SPACE! GAME OVER!");
                printf("COMPUTER WON\n");
                game_over = true;
            }
        }
        if((turn_limit_comp<0)){  //COMPUTER WIN
            /*if(checkComp(board,turn)){
                printf("GAME OVER! ");
                game_over = true;
                printf("COMPUTER WON\n");
            }*/
            printf("Reached the turn limit of the computer. ");
            printf("USER WON\n");
            game_over = true;
        }else{
            if(find_moveable(board,turn)>0){
                if(turn == comp){
                    move = comp_move(board,turn);
                    makeMove(board,move,turn);
                    turn_limit_comp--;
                    printBoard(board);
                    find_moveable(board,turn);
                    //turn = user;
                }
            }else if(find_moveable(board,turn)==0){
                printf("DO NOT FIND MOVEABLE SPACE! GAME OVER!");
                printf("USER WON\n");
                game_over = true;
            }
        }

        //CHECKS IF THE BOARD IS FULL
        if(isBoardFull(board)){
            printf("GAME OVER! IT'S A DRAW\n");
            game_over = true;
        }

      /*  //DRAW
        if(find_moveable(board,turn) == find_moveable(board,!turn)){
            printf("IT IS A DRAWN! GAME OVER!");
            game_over = true;
        }*/
        turn = !turn;
    }
}

int main(int argc, char *argv[]){
    run();
    return 0;
}
