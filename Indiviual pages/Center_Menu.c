
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void Centre_Menu()
{
    system("cls");
    Centre_Heading();
    printf("\n\tSelect and Enter Your Choice From Menu:\n");
    printf("\n\t================================");
    printf(" \n\t Enter 1 ->> Mansarover centre");
    printf("\n\t=================================");
    printf(" \n\t Enter 2 ->> Vaishali Nagar centre");
    printf("\n\t=================================");
    printf(" \n\t Enter 3 ->> jhotwara centre");
    printf("\n\t=================================\n");
    printf(" \n\t Enter 4 ->> Return to Home Page");
    printf("\n\t=================================\n");
    int choice;
    I:
    printf(" \nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)           // SWITCH STATEMENT
    {
        case 1: system("cls");
        Mansarover();
        break;
        case 2: Vaishali();
        break;
        case 3: Jhotwara();
        break;
        case 4: Second_Page();
        break;
        default: printf("\n\n\t\tInvalid Input----Enter Again : ");
        goto I;
    }
}