#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
char ch;

void Add_Page()
{
    char first_name[30],last_name[30],address[30],number[15],email[30],model[15],date[12];
    float cost,paid;
    int warranty, i;
    system("cls");
    Sales_Heading();
    printf("\n\n\t\t\t======Add Customer's Details======");
    P:
    printf("\n\n\t\t\t  First Name : ");
    scanf("%s",first_name);
    if(strlen(first_name)>25)
    {
        printf("\n\t\t\t  Invalid First Name----Maximum Character is 25----Try Again.");
        goto P;
    }
    else
    {
        int flag=1;
        for(i=0;i<strlen(first_name);i++)
        {
            if(isalpha(first_name[i]))
            {
              first_name[i]=toupper(first_name[i]);
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n\t\t\t  Invalid Input---Only Alphabets Allowed---Enter Again-");
            goto P;
        }
    }
    Q:
    printf("\n\t\t\t  Last Name : ");
    scanf("%s",last_name);
    if(strlen(last_name)>25)
    {
        printf("\n\t\t\t  Invalid First Name----Maximum Character is 25----Try Again.");
        goto Q;
    }
    else
    {
        int flag=1;
        for(i=0;i<strlen(last_name);i++)
        {
            if(isalpha(last_name[i]))
            {
               last_name[i]=toupper(last_name[i]);
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n\t\t\t  Invalid Input---Only Alphabets Allowed---Enter Again-");
            goto Q;
        }
    }
    R:
    printf("\n\t\t\t  Address : ");
    scanf("%s",address);
    if(strlen(address)>25)
    {
        printf("\n\t\t\tInvalid Input---Limit Exceeds---Try Again-");
        goto R;
    }
    else
    {
        for(int i=0;i<strlen(address);i++)
        {
            address[i]=toupper(address[i]);
        }
    }
    S:
    printf("\n\t\t\t  Phone Number : ");
    scanf("%s",number);
    if(strlen(number) != 10)
    {
        printf("\n\t\t\tInvalid Input---Ten Digits Required---Try Again-");
        goto S;
    }
    else
    {
        int flag=1;
        for(int i=0;i<strlen(number);i++)
        {
            if(isalpha(number[i]))
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n\t\t\tInvalid Input---Only Digits Accepted---Try Again-");
            goto S;
        }
    }
    T:
    printf("\n\t\t\t  Email : ");
    scanf("%s",email);
    if(strlen(email)>30 || strlen(email)<10)
    {
        printf("Invalid Input---Minimum Characters-10---Maximum Character-30---Try Again-");
        goto T;
    }
    U:
    printf("\n\t\t\t  Model Number : ");
    scanf("%s",model);
    if(strlen(model)>15)
    {
        printf("Invalid Input---Limit Exceeds---Maximum Character-15---Try Again-");
        goto T;
    }
    V:
    printf("\n\t\t\t  Warranty(No. of years) : ");
    scanf("%d",&warranty);
    if(warranty<0)
    {
        printf("\n\t\t\t  Invalid Input---Positive Integer Expected---Try Again-");
        goto V;
    }
    W:
    printf("\n\t\t\t Date of purchase(dd/mm/yyyy) : ");
    scanf("%s",date);
    if(strlen(date)!=10)
    {
        printf("\n\t\t\tInvalid Input---Ten Characters Required---Try Again-");
        goto W;
    }
    printf("\n\t\t\t  Cost(in Rs) To Be Paid : ");
    scanf("%f",&cost);
    printf("\n\t\t\t Money Paid(in Rs) : ");
    scanf("%f",&paid);

    FILE *ptr;
    ptr=fopen("List.txt","a");
    fprintf(ptr,"\n%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,warranty,date,cost,paid);
    printf("\n\n\t\t------------------------------------------------------------------");
    printf("\n\t\t\tDetails Has Been Added Successfully!!!!!!!");
    fclose(ptr);
    Y:
    fflush(stdin);
    printf("\n\n\t\tDo You Want TO Add More----(Y/N) : ");
    scanf("%s",&ch);
    if(toupper(ch)=='Y')
    {
        Add_Page();
    }
    else if(toupper(ch)=='N')
    {
        printf("\n\n\t\tOk....Done----");
        getch();
        MenuPage();
    }
    else
    {
       printf("\n\n\t\tInvalid Input----Enter Again--");
       goto Y;
    }
}