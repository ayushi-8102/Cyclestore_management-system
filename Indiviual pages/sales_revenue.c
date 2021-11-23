#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void sales_revenue()
{
    system("cls");
    Sales_Heading();
    printf("\n\n\t\t\t-----------------Sales Revenue Details------------------");
    float total=0;
    char first_name[30],last_name[30],address[30],number[15],email[30],model[15],date[12];
    float cost,paid;
    int warranty,count=0;
    FILE *ptr;
    ptr=fopen("List.txt","r");
    while(fscanf(ptr,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,&warranty,date,&cost,&paid)!=EOF)
    {
        total=total+paid;
        count++;
    }
    printf("\n\n\t\t\t\tNo Of Cycle Sold : %d",count);
    printf("\n\t\t\t\tTotal Sales Revenue : Rs%0.2f",total);
    fclose(ptr);
    printf("\n\n\t\tPress any key to return to Menu Page--- ");
    getch();
    MenuPage();
}