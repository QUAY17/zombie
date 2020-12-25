/***************************************************************************
 * @file    zombie.c
 * @brief   Zombie Apocolypse function definitions
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
#define LEN 32

/** finds the time from user input
 * @param a[] the char array for input
 * @param data[] array for zombie struct
 * @param i index for array
 */
void input_time(char a[], struct zombie data[], int i) //function to input the day and the time
{
    
    printf("\nPlease choose the day this zombie was encountered:\n1) Monday\n2) Tuesday\n3) Wednesday\n4) Thursday\n5) Friday\n6) Saturday\n7) Sunday\n");
    fgets(a, LEN, stdin);
    data[i].day = atoi(a);
    
    printf("\nEnter time when this zombie was encountered. Separate hours, minutes, and seconds by colons like HH:MM:SS\n");
    fgets(a, LEN, stdin);
    sscanf(a, "%d:%d:%d", &data[i].hour, &data[i].min, &data[i].sec);
    //input checks
    if (data[i].hour > 24 || data[i].hour < 0)
    {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("A zombie has attacked! (You entered something I don't understand). \n\n");
    }
    if (data[i].min > 60 || data[i].hour < 0)
    {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("A zombie has attacked! (You entered something I don't understand). \n\n");
    }

    if (data[i].sec > 60 || data[i].hour < 0)
    {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("A zombie has attacked! (You entered something I don't understand). \n\n");
    }

}

/** finds the number of toes from user input
 * @param a[] the array to print
 * @return the number of toes
 */
void input_toes(char a[], struct zombie data[], int i) // function to input the number of toes the dead zombie has
{
 
    printf("\nPlease enter the number of toes the zombie has: ");
    fgets(a, LEN, stdin);
    data[i].toes = atoi(a);
}

/** finds the amount of blood from user input
 * @param a[] the array to print
 * @return the number of toes
 */
void input_blood(char a[], struct zombie data[], int i) //function to input how much blood oozes from an undead zombie once its killed
{

    printf("\nPlease enter the amount of blood that oozed from its body after you killed it (in mL): ");
    fgets(a, LEN, stdin);
    data[i].blood = atof(a);
}

/** finds the maximum value from array a
 * @param a[] the array to print
 * @param size the size or length of the array
 * @return max of the array
 */
void print_zombies(char a[], struct zombie data[], int i, int dead) //function that displays all of the zombie information you have entered into the database
{
    data[i].dead = dead;
    //loop index
    for (i = 0; i < SIZE; i++)
    {
        if (data[i].dead == 'N')
        {
            printf("\n%d. This zombie was found ALIVE.\n", i+1);
            printf("It was drained of %f mL of blood once killed.\n", data[i].blood);
            //convert enum back to string :( to print days
            switch (data[i].day)
            {
                case MONDAY:
                    printf("This zombie was sighted Monday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;
                case TUESDAY:
                    printf("This zombie was sighted Tuesday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;
                case WEDNESDAY:
                    printf("This zombie was sighted Wednesday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;
                case THURSDAY:
                    printf("This zombie was sighted Thursday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;  
                case FRIDAY:
                    printf("This zombie was sighted Friday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;
                case SATURDAY:
                    printf("This zombie was sighted Saturday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break; 
                case SUNDAY:
                    printf("This zombie was sighted Sunday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;
            }
        } else if (data[i].dead  == 'Y')
        {
            printf("\n%d. This zombie was found dead.\n", i+1);
            printf("This zombie had %d toes.\n", data[i].toes);
            //convert enum back to string :( to print days
            switch (data[i].day)
            {
                case MONDAY:
                    printf("This zombie was sighted Monday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;
                case TUESDAY:
                    printf("This zombie was sighted Tuesday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;
                case WEDNESDAY:
                    printf("This zombie was sighted Wednesday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;
                case THURSDAY:
                    printf("This zombie was sighted Thursday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;  
                case FRIDAY:
                    printf("This zombie was sighted Friday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;
                case SATURDAY:
                    printf("This zombie was sighted Saturday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break; 
                case SUNDAY:
                    printf("This zombie was sighted Sunday at %d:%d:%d\n", data[i].hour, data[i].min, data[i].sec);
                break;
            }

        }
    }  

}



