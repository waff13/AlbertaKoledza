//  Created by Vladimir Iotchenko.
//  Copyright © 2018 Vladimir Iotchenko. All rights reserved.
//
// Izstrādāt C programmu, kas aprēķina pāra skaitļu īpatsvaru starp visiem masīvā esošajiem veseliem skaitļiem.
// Programmā paredzēt:
//  Veselo skaitļu ievadu no tastatūras.
//  Ievadīto skaitļu pārbaudi. Ja ievadītā vērtība nav vesels skaitlis tad paziņot par kļūdu un atkārtot ievadu.
//  Ja ievada tukšu rindu (nospiests tikai Enter), tad pabeidz skaitļu ievadu un pāriet pie aprēķiniem.
//  Ja nepieciešams beigt programmu pirms ir ievadīti visi skaitļi, paredzēt iespēju, ka ievadot frāzi 
// “exit” (not case sensitive) programma beidz darbību.
//  Pēc skaitļu ievada attēlot visus skaitļus uz ekrāna un attēlot cik daudz procentuāli no visiem skaitļiem ir pāra skaitļ
//
//  AK Programming course part I. Task 001.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void calculate (int numbers[], int counter);

int main ()
{
    char input[8];                              // An array to store input from user
    int numbers[16];                            // An array to store given numbers
    int counter = 0;
    
    for (; ;)
    {
        printf ("Enter your number: ");
        fgets (input, sizeof(input), stdin);    // Getting input from user
       
        for (int i = 0; i < (sizeof(input)/sizeof(input[0])); i++)
        {
            input[i] = toupper(input[i]);       // Formatting input so user can input "Exit" in any case (EXIT, exit...) 
        }
        
        if (!strcmp (input, "EXIT\n"))
        {
            printf ("*****Exit requested!*****\n");
            break;
        }

        if (!strcmp (input, "\n"))              // If no input is given, proceed to calculations
        {
            printf ("*****Calculating...*****\n");
            calculate (numbers, counter);
            break;
        }
        
        for (int i = 0; i < (sizeof(input)/sizeof(input[0])); i++)
        {
            if (!strcmp(&input[i], "\n"))
            {
                numbers[counter] = atoi(input); // Converting input to int and putting it into array 
                counter++;
                break;
            }

            if (!isdigit(input[i]))             // Ignoring all input that is not a digit
            {
                printf("Not really a number, try again!\n");
                break;
            }
            
        }
        
    }

    return 0;
}

void calculate (int numbers[], int counter)
{
    printf ("Here are your numbers: ");
    double evenCounter = 0.0;
    for (int i = 0; i < counter; i++)
    {
        printf ("%d ", numbers[i]);
        if (numbers[i] % 2 == 0) evenCounter ++;    // Finding even numbers 
    }
    printf ("\nOf them %.2f per cent are even\n", (evenCounter * 100/counter)); // Printing result as percentage
}
