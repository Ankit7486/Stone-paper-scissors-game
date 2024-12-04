/*
    STONE-PAPER-SCISSOR Game in C
    Description: A C program for Stone-Paper-Scissor, featuring random computer choices, ASCII Art and Loop for continous play.
    Author: Ankit Raj
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool loop = true;

void display_ascii_art(int choice)
{
    if (choice == 0)
    {
        printf("           _______\n");
        printf("      ---'   ____)__\n");
        printf("                ____)\n");
        printf("                _____)\n");
        printf("               _____)\n");
        printf("      ---.________)\n");
        printf("             Stone\n");
    }
    else if (choice == 1)
    {
        printf("             _______\n");
        printf("        ---'   ____)____\n");
        printf("                  ______)\n");
        printf("                  _______)\n");
        printf("                 _______)\n");
        printf("        ---.__________)\n");
        printf("             Paper\n");
    }
    else if (choice == 2)
    {
        printf("           _______\n");
        printf("      ---'   ____)____\n");
        printf("                ______)\n");
        printf("             __________)\n");
        printf("            (____)\n");
        printf("      ---.__(___)\n");
        printf("             Scissor\n");
    }
}

void display_intro()
{
    printf("ENTER 0 FOR STONE\n");
    printf("ENTER 1 FOR PAPER\n");
    printf("ENTER 2 FOR SCISSOR\n");
    printf("-> enter 69 to exit\n");
    printf("ENTER YOUR CHOICE = ");
}

void game()
{
    display_intro();

    int computer_choice, user_choice;
    scanf("%d", &user_choice);
    if (user_choice == 69)
    {
        loop = false;
        return;
    }

    while (user_choice < 0 || user_choice > 2)
    {
        printf("INVALID SELECTION!\n");
        printf("ENTER AGAIN: ");
        scanf("%d", &user_choice);
    }

    computer_choice = rand() % 3;

    printf("\nYOUR CHOICE:\n");
    display_ascii_art(user_choice);
    printf("\nCOMPUTER'S CHOICE:\n");
    display_ascii_art(computer_choice);

    if (user_choice == 0 && computer_choice == 1)
        printf("\n!!YOU LOSE!!\n");
    else if (user_choice == 1 && computer_choice == 2)
        printf("\n!!YOU LOSE!!\n");
    else if (user_choice == 2 && computer_choice == 0)
        printf("\n!!YOU LOSE!!\n");
    else if (user_choice == computer_choice)
        printf("\n!!IT'S A TIE!!\n");
    else
        printf("\n!!YOU WIN!!\n");

    printf("\n\n\n");
}

int main()
{
    srand(time(NULL));
    system("cls");
    printf("***********  GAME  *************\n");
    while (loop)
    {
        game();
    }
    return 0;
}
