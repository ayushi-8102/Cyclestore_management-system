#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void rent_revenue()
{
    system("cls");
    Sales_Heading();
    printf("\n\n\t\t\t-----------------Rental Revenue Details------------------");
    int total=0;
    char modelnumber[25],firstname[25],lastname[25],address[25],phonenumber[25],nationality[25],email[25];
    int period;
    int count=0;
    FILE *ptr;
    ptr=fopen("add.txt","r");
    while(fscanf(ptr,"%s %s %s %s %s %s %s %d", modelnumber, firstname, lastname, address, phonenumber, nationality, email, &period)!=EOF)
    {
        total=total+period*20;
        count++;
    }
    printf("\n\n\t\t\t\tNo Of Cycle On Rent : %d",count);
    printf("\n\t\t\t\tTotal Rental Revenue : Rs%d",total);
    fclose(ptr);
    printf("\n\n\t\tPress any key to return to Menu Page--- ");
    getch();
    Rent_Menu();
}