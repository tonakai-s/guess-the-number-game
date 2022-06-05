#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(){
    time_t t;
    srand((unsigned) time(&t));

    int inputedNumber, playsLeft;
    int userTries = 1;
    char tryAgain;

    
    printf("Welcome, this is a guessing game.\n");
    printf("I have chosen a number between 0 and 30 which you must guess.\n");
    startGame : int randomNumber = rand() % 31;

    printf("To start, inform your first number: ");
    scanf("%d", &inputedNumber);

    while(userTries <= 5){
        while(inputedNumber < 0 || inputedNumber > 30){
            printf("%d is a invalid number, please enter a number between 0 and 30: ", inputedNumber);
            scanf("%d", &inputedNumber);
        }
        if(inputedNumber != randomNumber){
            randomNumber > inputedNumber ? printf("Sorry, %d is wrong. My number is greater than that.\n", inputedNumber) : printf("Sorry, %d is wrong. My number is less than that.\n", inputedNumber);
        } else {
            printf("Congratulations, you have guessed the number!! =]");
                break;
        }

        playsLeft = 5 - userTries;
        if(playsLeft > 0){
            printf("You have more %d chances, inform another number: ", playsLeft);
            scanf("%d", &inputedNumber);
        } else {
            printf("Sorry, you not have more chances :/");
                break;
        }

        userTries++;
    }

    printf("\nWanna play again? (Y/N)");
    scanf("%s", &tryAgain);
    tryAgain = toupper(tryAgain);
    if(tryAgain == 'Y'){
         goto startGame;
    }
    
    return 0;
}