#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
int flag=0;
void Delete_Page()
{
    system("cls");
    Sales_Heading();
    printf("\n\n\t\t\t--------------Delete Customer's Details-------------");
    char name[25];
    char first_name[30],last_name[30],address[30],number[15],email[30],model[15],date[12];
    float cost,paid;
    int warranty;
    FILE *ptr,*ptr1;
    ptr=fopen("List.txt","r");
    ptr1=fopen("temp_List.txt","w+");
    printf("\n\n\t\t\t\tEnter Customer's First Name : ");
    fflush(stdin);
    scanf("%s",name);
    for(int i=0;i<strlen(name);i++)
    {
        name[i]=toupper(name[i]);
    }
    fflush(stdin);
    flag=0;
    while(fscanf(ptr,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,&warranty,date,&cost,&paid)!=EOF)
    {
        if(strcmp(first_name,name)==0)
        {
          printf("\n\n%s %-20s%-20s%-20s%-25s%-20s%-20d%-20s%-20.2f%-20.2f\n",first_name,last_name,address,number,email,model,warranty,date,cost,paid);
          flag=1;
        }
        else
        {
          fprintf(ptr1,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,warranty,date,cost,paid);
        }
    }
    if(flag==0)
    {
        printf("\n\n\t\t\tData Not Found-----");
        getch();
        MenuPage();
    }
    else
    {
        fclose(ptr);
        fclose(ptr1);
        remove("List.txt");
        rename("temp_List.txt","List.txt");
        printf("\n\n\t\t\tData Has Been Deleted Successfully-------");
        getch();
        MenuPage();
    }

}