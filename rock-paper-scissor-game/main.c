#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define ROCK 1
#define PAPER 2
#define SCISSOR 3
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 0

int rock_paper_scissor(int player1,int player2){
    int result;
    if(player1==ROCK && player2==PAPER){
        result=PLAYER2_WIN;
    }
    else if(player1==ROCK && player2==SCISSOR){
        result=PLAYER1_WIN;
    }

    else if(player1==PAPER && player2==ROCK){
        result=PLAYER1_WIN;
     }
    else if(player1==PAPER && player2==SCISSOR){
        result=PLAYER2_WIN;
    }

    else if(player1==SCISSOR && player2==ROCK){
         result=PLAYER2_WIN;
    }
    else if(player1==SCISSOR && player2==PAPER){
        result=PLAYER1_WIN;
    }

    else{
        result=DRAW;
    }

    return result;
}

int get_user_choice(){
        int choice;
        do{
            printf("1.Rock \n");
            printf("2.Paper \n");
            printf("3.Sicssor \n");
            printf("select the choice[1,2,3] (in betlween 1 to 3 only otherwise u stare at infinite loop ha ha ha ): ");
            scanf("%d",&choice);
            if(!(choice>=1&&choice<=3)){
                printf("Error -Invalid choice details,should be 1 or 2 or 3 \n");
            }
        }while(!(choice>=1&&choice<=3));
    return choice;
}

void print_word(int v){
    if(v==ROCK){
        printf("Rock \n");
    }
    else if(v==PAPER){
        printf("Paper \n");
    }
    else if(v==SCISSOR){
        printf("Scissor \n");
    }
}

int main()
{
    int user_score=0;
    int computer_score=0;

    srand(time(NULL));
    int quit=0;

    while(!quit){
        int user_choice=get_user_choice();
        int computer_choice=(rand()%3)+1;

        printf("User Choice : ");
        print_word(user_choice);

        printf("Computer Choice : ");
        print_word(computer_choice);

        int result=rock_paper_scissor(user_choice,computer_choice);
        if(result==DRAW){
            printf("it Draw \n");
        }
        else if(result==PLAYER1_WIN){
            printf("User Win and Computer lost the round \n");
            user_score++;
        }
        else if(result==PLAYER2_WIN){
            printf("Computer  Win and User lost the round \n");
            computer_score++;
        }
        printf("\n");
        printf("-------------------------------------------\n");
        printf("User score: %d\n",user_score);
        printf("Computer score: %d\n",computer_score);
        printf("---------------------------------------------\n");
        printf("\n\n");

        printf("do you want to continue this game Enter any integer ,or Enter 0 to Terminate\n");
        int respose;
        scanf("%d",&respose);
        if(respose==0)
            quit=1;
    }//End of the While :)

     printf("Final Scores : ");
     printf("\n");
     printf("\n");
     printf("--------------------------------------------\n");
     printf("User score: %d\n",user_score);
     printf("Computer score: %d\n",computer_score);
     printf("---------------------------------------------\n");
     printf("\n\n");

     if(user_score==computer_score){
        printf("GAME WAS DRAW\n");
     }
     else if(user_score>computer_score){
        printf("USER WON THE MATCH\n");
     }
     else
        printf("COMPUTER WON THE MATCH\n");

    return 0;
}

