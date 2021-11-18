#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void Search_Page()
{
    system("cls");
    Sales_Heading();
    printf("\n\n\t\t\t-----------------Search Customer's Details------------------");
    char phone[25];
    char first_name[30],last_name[30],address[30],number[15],email[30],model[15],date[12];
    float cost,paid;
    int warranty;
    FILE *ptr;
    ptr=fopen("List.txt","r");
    printf("\n\n\t\t\t\tEnter Customer's Phone No or First Name : ");
    scanf("%s",phone);
    for(int i=0;i<strlen(phone);i++)
    {
        phone[i]=toupper(phone[i]);
    }
    int option=0;
    printf("%-20s%-20s%-20s%-25s%-20s%-20s%-20s%-20s%-20s\n","Full Name","Address","Phone Number","Email Address","Model Number","Warranty","Date of Purchase","Cost","Amount Paid");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    while(fscanf(ptr,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,&warranty,date,&cost,&paid)!=EOF)
    {
        if(strcmp(phone,number)==0 || strcmp(phone,first_name)==0)
        {
            char space[5]=" ";
            strncat(first_name,space,sizeof(first_name)-sizeof(space)-1);
            strncat(first_name,last_name,sizeof(first_name)-sizeof(last_name)-1);
            printf("%-20s%-20s%-20s%-25s%-20s%-20d%-20s%-20.2f%-20.2f\n",first_name,address,number,email,model,warranty,date,cost,paid);
            option=1;
        }
    }
    if(option==0)
    {
        printf("\n\n\t\t\t\tNo Data Found");
    }
    fclose(ptr);
    printf("\n\n\t\tPress any key to return to Menu Page--- ");
    getch();
    MenuPage();
}