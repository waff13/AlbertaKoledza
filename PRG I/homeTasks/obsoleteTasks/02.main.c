//  Created by Vladimir Iotchenko.
//  Copyright © 2018 Vladimir Iotchenko. All rights reserved.
//
// Izstrādāt C programmu, kas ļauj dažādos veidos pārveidot ievadīto teksta rindu.
// Programmas darbība:
//  Sākumā lietotājam piedāvā ievadīt teikumu (teksta rindu).
//  Pēc teksta ievada (Enter nospiešanas) uz ekrāna izvadīt vienkāršu izvēlni saraksta veidā kur katra 
// rinda satur komandu un atbilstīgu simbolu komandas aktivizēšanai, piemēram:
//    A Pirmā komanda 
//    B Otrā komanda
//    utt.
//    ESC Beigt programmu
//  Pēc komandas izvēles ievadīto tekstu pārveidots atbilstīgos veidos:
//  Visi burti tiek pārveidoti par augšējā reģistra burtiem.
//  Visi burti tiek pārveidoti par apakšējā reģistra burtiem.
//  Katra vārda pirmais burts tiek pārveidots par augšējā reģistra burtu.
//  Teikuma vārdi tiek salikti pretējā secībā.
//  Visi teikuma simboli tiek izvietoti pretējā virzienā lai teikumu varētu lasīt no labās puses.
//  Attēlot divās jaunās rindās ievadīto un pārveidoto tekstu.
//  Atkal atgriezties pie izvēlnes.
// 
// Programmas prasības
//  Teksta rindas garumam ir jābūt ne mazāk kā 20 un ne vairāk kā 50 simboli. Teikumam ir jāsatur 
// vismaz 3 vārdi. Ja ievadītā teksta rinda neatbilst prasībām, tad paziņot par kļūdu un piedāvāt 
// ievadīt no jauna.
//  Paredzēt atsevišķu komandu programmas beigšanai.
//
//  AK Programming course part I. Task 002.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void displayMenu();
void toUpperCase(char *array, int lineLength);
void toLowerCase(char *array, int lineLength);
void firstLettersUp (char *array, int lineLength);
void wordsBackwards (char *array);
void lineReverse(char *array, int lineLength);

int main ()
{
    char inputString[64];
   
    for (;;)                                                // Prompting user for input
    {
        printf ("Text string or 'exit' to quit: ");
        fgets (inputString, sizeof(inputString), stdin);
        if (!strcmp(inputString, "exit\n"))                 // Program quits if user types "exit"
        {
            printf("Exiting... bye!\n");
            return 1;
        }
        
        int lineLength = 0;
        int spaceCount = 0;
        for (int i = 0; i < 64; i++)                        // Counting the lenght of the line and number of spaces
        {
            if (inputString[i] == ' ')
            {
                spaceCount++;
            }
            
            if (inputString[i] == '\0')
            {
                lineLength = i;
                break;
            }
        }
        
        if ((lineLength < 20) || (lineLength > 50))
        {
            printf("There should be >20 and <50 symbols in the input string, please try again!\n");
            continue;
        }
        
        if (spaceCount < 2)                                 // Spaces show the number of words
        {
            printf("There should be more words!\n");
            continue;
        }
        
        char original[64];
        strcpy(original, inputString);                      // Making original string intact via a copy of array
        
        for (;;)                                            // Endless loop with selection menu
        {
            displayMenu();
            char choice[2];
            scanf("%[^\n]%*c", choice);
            int selection = atoi(choice);
            
            switch (selection)
            {
                case (1):
                    toUpperCase(inputString, lineLength);
                    break;
                case (2):
                    toLowerCase(inputString, lineLength);
                    break;
                case (3):
                    firstLettersUp(inputString, lineLength);
                    break;
                case (4):
                    wordsBackwards(inputString);
                    break;
                case (5):
                    lineReverse(inputString, lineLength);
                    break;
                case(0):
                    printf("Good-bye!\n");
                    return 0;
                default:
                    printf("Only (1), (2), (3), (4), (5) or (0) to exit, please!\n");
                    continue;
            }
            printf("Original line: %s\n", original);
        }
        
    }
    return 0;
}

void displayMenu()                                          // User menu with command options
{
    printf ("Make your choice: \n");
    printf (" 1 - all letters to upper case\n");
    printf (" 2 - all letters to lower case\n");
    printf (" 3 - first letters to upper case\n");
    printf (" 4 - all words to backwards direction\n");
    printf (" 5 - reverse the whole line\n");
    printf (" 0 - exit\n");
}

void toUpperCase (char *array, int lineLength)
{
    int i = 0;
    while (i < (lineLength - 1))
    {
        if ((array[i] > 96) && (array[i] < 123))            // Check if the current symbol is a small letter
        {
            array[i] = (array[i] - 32);
        }
        printf("%c", array[i]);
        i++;
    }
    printf("\n");
}

void toLowerCase (char *array, int lineLength)
{
    for (int i = 0; i < (lineLength - 1); i++)
    {
        if ((array[i] > 64) && (array[i] < 91))             // Check if the current symbol is a capital letter
        {
            array[i] = (array[i] + 32);
        }
        printf("%c", array[i]);
    }
    printf("\n");
}

void firstLettersUp (char *array, int lineLength)
{
    if ((array[0] > 96) && (array[0] < 123))                // Check if the firs letter is a small letter
    {
        array[0] = (array[0] - 32);                         // If it is, making it a capital letter 
    }
    
    for(int i = 0; i < (lineLength - 1); i++)
    {
        if (array[i] == ' ')                                // Check if the current symbol is a space
        {
            if ((array[i+1] > 96) && (array[i+1] < 123))    // If yes and the following symbol is a small letter
            {
                array[i+1] = (array[i+1] - 32);             // Making that following symbol a capital letter
            }
        }
        printf("%c", array[i]);
    }
    printf("\n");
    
}

void wordsBackwards (char *array)
{
    int end = (int) (strlen(array) - 2);        // Getting the length of the string, might as well use "lineLength"
    int start = end;                            // It is here the word starts and ends
    
    for (int i = end; i > 0; i--)
    {
        if (array[start] == ' ')                // Moving backwards from the end until a space symbol is found
        {
            for (int j = (start + 1); j <= end; j++)
            {
                printf("%c", array[j]);         //  Then printing the word in the correct direction
            }
            printf(" ");
            end = (start - 1);
        }
        start = start - 1;
    }
    
    for (int i = 0; i < (end + 1); i++)         // Printing the first (last) word
    {
        printf("%c", array[i]);
    }
    printf("\n");
    
}

void lineReverse (char *array, int lineLength)
{
    for (int i = (lineLength - 2); i >= 0; i--) // Printing the line backwards, from end to start
    {
        printf("%c", array[i]);
    }
    printf("\n");
}
