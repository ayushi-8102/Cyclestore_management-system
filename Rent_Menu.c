#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void Rent_Menu()
{
    system("cls");
    Rent_Heading();
    printf("\n\tSelect and Enter Your Choice From Menu:\n");
    printf("\n\t================================");
    printf(" \n\t Enter 1 ->> Rent a cycle");
    printf("\n\t=================================");
    printf(" \n\t Enter 2 ->> View Rental Record");
    printf("\n\t=================================");
    printf(" \n\t Enter 3 ->> Total Revenue");
    printf("\n\t=================================\n");
    printf(" \n\t Enter 4 ->> Return to Home Page");
    printf("\n\t=================================\n");
    int choice;
    H:
    printf(" \nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)           // SWITCH STATEMENT
    {
        case 1: system("cls");
        rent_cycle();
        break;
        case 2: cycle_record();
        break;
        case 3: rent_revenue();
        break;
        case 4: Second_Page();
        break;
        default: printf("\n\n\t\tInvalid Input----Enter Again : ");
        goto H;
    }