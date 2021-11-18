#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


void List_Page()
{
    system("cls");
    Sales_Heading();
    printf("\n\n\n\t\t\t---------------Customer's List---------------\n");
    FILE *ptr;
    ptr=fopen("List.txt","r");
    //printf("\n  Name\t\tAddress\t Phone Number\tEmail Address\t\t\tModel Number\tWarranty\tDate of Purchase\t\tCost\tAmount Paid");
    printf("%-20s%-20s%-20s%-25s%-20s%-20s%-20s%-20s%-20s\n","Full Name","Address","Phone Number","Email Address","Model Number","Warranty","Date of Purchase","Cost","Amount Paid");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    char first_name[30],last_name[30],address[30],number[15],email[30],model[15],date[12];
    float cost,paid;
    int warranty;
    rewind(ptr);
    while(fscanf(ptr,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,&warranty,date,&cost,&paid)!=EOF)
    {
        char space[5]=" ";
        strncat(first_name,space,sizeof(first_name)-sizeof(space)-1);
        strncat(first_name,last_name,sizeof(first_name)-sizeof(last_name)-1);
        printf("%-20s%-20s%-20s%-25s%-20s%-20d%-20s%-20.2f%-20.2f\n",first_name,address,number,email,model,warranty,date,cost,paid);
    }
    fclose(ptr);
    printf("\n\n\nPress any key to continue---");
    getch();
    MenuPage();
}