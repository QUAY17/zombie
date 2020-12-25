/***************************************************************************
 * @file    lab6.c
 * @brief   Zombie Apocolypse main function
 * @author  Jennifer Quay Minnich
 * @date    Oct 20, 2020
 *
 * @details This program is a Zombie Apocolypse log that will keep track of the 
 *          zombies encountered. This program uses structs, enumerations, and 
 *          arrays, along with fgets and sscanf for user input.
 *
 * @bug none
 *
 * @todo none
 **************************************************************************/
 
#include "zombie.h"
#include <stdio.h>
#include <stdlib.h>

#define ENTER_ZOMBIE 1
#define DISPLAY_INFO 2
#define QUIT 3
#define LEN 32

int main(void)
{
    struct zombie data[SIZE];

    char buf[LEN];
    char dead;
    int i = -1;
    int menu;

    while (1)
    {
        printf("\n1. Enter new zombie information\n");
        printf("2. Display zombie information\n");
        printf("3. Return to fighting zombies (exit)\n");
        printf("Enter selection: ");
        fgets(buf, LEN, stdin);
        menu = atoi(buf);

        switch(menu) 
        {
            case ENTER_ZOMBIE:
                //index will store up to 5 zombies in database
                i = (i +1) % 5;
                printf("\nWas the zombie found dead? Y or N : ");
                fgets(buf, LEN, stdin);
                sscanf(buf, "%c", &dead);

                switch (dead)
                {
                    case 'Y':
                    case 'y':
                        //call function input_toes
                        input_toes(buf, data, i);
                        //call function input_time
                        input_time(buf, data, i);
                        break;
                    case 'N':
                    case 'n':
                        //call input_blood
                        input_blood(buf, data, i);
                        //call function input_time
                        input_time(buf, data, i);
                        break;
                } 
            break;
            case DISPLAY_INFO:
                print_zombies(buf, data, i, dead);
            break;
            case QUIT:
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Stay alert! Keep a watch out for zombies!!\nGOODBYE and GOOD LUCK!\n");
                exit(EXIT_SUCCESS);
            break;
            default:
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("A zombie has attacked! (You entered something I don't understand). \n\n");
            break;
        }
    };

    return 0;
}
