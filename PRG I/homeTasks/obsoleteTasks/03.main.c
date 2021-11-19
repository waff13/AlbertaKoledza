//  Created by Vladimir Iotchenko.
//  Copyright © 2018 Vladimir Iotchenko. All rights reserved.
//
// Izstrādāt C programmu, kas ļauj veidot vienkāršu teksta failu.
// Programmas darbība:
//  Programma tiek palaista no komandas rindas ar vienīgo parametru – veidojama faila nosaukumu. 
// Piemēram: application story.txt
//  Programmas darbības sākumā tiek nolasīts parametrs no komandas rindas un tiek izveidots un 
// atvērts jauns tukšs teksta fails programmas tekošā katalogā vai katalogā, kas ir norādīts kopā ar 
// faila nosaukumu (path). Piemēram, application c:\myfolder\story.txt
//  Ja parametrs ar faila nosaukumu nav, tad paziņot par kļūdu un beigt programmu.
//  Ja fails ar doto nosaukumu jau eksistē tad paziņot par kļūdu un beigt programmu.
//  Kad fails ir atvērts, lietotājam tiek piedāvāts ievadīt tekstu (var aprobežoties ar vienu ekrāna 
// rindas garumu). Pēc Enter nospiešanas ievadītā teksta rinda (rindkopa, kopā ar jaunas rindas 
// kodu) tiek ierakstīta teksta faila beigās un tiek piedāvāts ievadīt nākamo teksta rindu.
//  Teksta rakstīšana beidzās, kad jaunajā rindā tiek ievadīts punkts un Enter. Tad šī rinda failā 
// netiek ierakstīta bet tiek aizvērts fails un programma beidz darbību.
//
//  AK Programming course part I. Task 003.
//  Path to file is "/Users/!!!USERNAME_SHOULD_BE_HERE!!!/Documents/MyStory.txt"

#include <stdio.h>
#include <string.h>

int main (int argc, const char *argv[])
{
    char input[64];
    FILE *file;
    
    if (argc != 2)                                      // Checking the amount of arguments given, shoul be 2
    {
        printf("No file name or path is given!\n");
        return 1;
    }
    
    if ((file = fopen(argv[1], "r")) != NULL)           // Checking if file already exist by opening it
    {
        printf("Error: file already exists!\n");
        fclose(file);                                   // Closing the file and exiting
        return 1;
    }
    
    file = fopen(argv[1], "a");                         // Opening file in append mode
    for (;;)
    {
        printf("Input your string: ");
        scanf("%[^\n]%*c", input);                      // Getting input string from user
        if (!strcmp(input, "."))                        // If user enters ".", breaking out of the loop
        {
            printf("Good-bye!\n");
            break;
        }
        fprintf(file,"%s ",input);                      // Writing user string to file
    }

    fclose(file);                                       // Closing the file
    return 0;
}
