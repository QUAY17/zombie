/***************************************************************************
 * @file    zombie.h
 * @brief   Zombie Apocolypse function declarations
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
 
#include <stdlib.h>
#ifndef ZOMBIE_H_
#define ZOMBIE_H_
#define SIZE 5

struct zombie {
    enum {MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} day;
    float blood;
    int toes;
    int hour;
    int min;
    int sec;
    char dead; /*y if dead, n if alive*/
};

void input_time(char a[], struct zombie data[], int i); //function to input the day and the time
void input_toes(char a[], struct zombie data[], int i); // function to input the number of toes the dead zombie has
void input_blood(char a[], struct zombie data[], int i); //function to input how much blood oozes from an undead zombie once its killed
void print_zombies(char a[], struct zombie data[], int i, int dead); //function that displays all of the zombie information entered in database

#endif

