#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
char ch;
void rent_cycle()
{
    system("cls");
    Rent_Heading();
    printf("\n\n\n");
	FILE *f;
    f = fopen("add.txt","a");
    if(f == NULL)
    {
        printf("Unable to open the file");
        Rent_Menu();
    }
	rewind(f);
	char modelnumber[25],firstname[25],lastname[25],address[25],phonenumber[25],nationality[25],email[25];
	unsigned int period;
	printf("\n\n\t\t\t======Add Customer's Details======");
	printf("\n\n\t\t\tModel No : ");
	scanf("%s",modelnumber);
    A:
    printf("\n\t\t\t  First Name : ");
    scanf("%s",firstname);
    if(strlen(firstname)>25)
    {
        printf("\n\t\t\t  Invalid First Name----Maximum Character is 25----Try Again.");
        goto A;
    }
    else
    {
        int flag=1;
        for(int i=0;i<strlen(firstname);i++)
        {
            if(isalpha(firstname[i]))
            {
              firstname[i]=toupper(firstname[i]);
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
            goto A;
        }
    }
    M:
    printf("\n\t\t\tLast Name : ");
    scanf("%s",lastname);
    if(strlen(lastname)>25)
    {
        printf("\n\t\t\t  Invalid First Name----Maximum Character is 25----Try Again.");
        goto M;
    }
    else
    {
        int flag=1;
        for(int i=0;i<strlen(lastname);i++)
        {
            if(isalpha(lastname[i]))
            {
              lastname[i]=toupper(lastname[i]);
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
            goto M;
        }
    }
    B:
    printf("\n\t\t\t  Address : ");
    scanf("%s",address);
    if(strlen(address)>25)
    {
        printf("\n\t\t\tInvalid Input---Limit Exceeds---Try Again-");
        goto B;
    }
    else
    {
        for(int i=0;i<strlen(address);i++)
        {
            address[i]=toupper(address[i]);
        }
    }
    C:
    printf("\n\t\t\t  Phone Number : ");
    scanf("%s",phonenumber);
    if(strlen(phonenumber) != 10)
    {
        printf("\n\t\t\tInvalid Input---Ten Digits Required---Try Again-");
        goto C;
    }
    else
    {
        int flag=1;
        for(int i=0;i<strlen(phonenumber);i++)
        {
            if(isalpha(phonenumber[i]))
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n\t\t\tInvalid Input---Only Digits Accepted---Try Again-");
            goto C;
        }
    }
    printf("\n\t\t\tNationality : ");
    scanf("%s",nationality);
    D:
    printf("\n\t\t\t  Email : ");
    scanf("%s",email);
    if(strlen(email)>30 || strlen(email)<10)
    {
        printf("Invalid Input---Minimum Characters-10---Maximum Character-30---Try Again-");
        goto D;
    }
    int opt;
    F:
    printf("\n\t\t\tPeriod (No of Hours) : ");
    scanf("%u",&period);
	fprintf(f,"%s %s %s %s %s %s %s %u\n", modelnumber, firstname, lastname, address, phonenumber, nationality, email, period);
	printf("\n\n\t\t------------------------------------------------------------------");
    printf("\n\t\t\tDetails Has Been Added Successfully!!!!!!!");
    fclose(f);
    G:
    fflush(stdin);
    printf("\n\n\t\tDo You Want TO Add More----(Y/N) : ");
    scanf("%s",&ch);
    if(toupper(ch)=='Y')
    {
        system("cls");
        rent_cycle();
    }
    else if(toupper(ch)=='N')
    {
        printf("\n\n\t\tOk....Done----");
        getch();
        Rent_Menu();
    }
    else
    {
       printf("\n\n\t\tInvalid Input----Enter Again--");
       goto G;
    }
}