#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void FirstPage();
void LoginPage();
void MenuPage();
void Heading();
void Add_Page();
void List_Page();
void Update_Page();
void Search_Page();
void Delete_Page();
void Rent_Menu();
void cycle_record();
void rent_cycle();
void sales_revenue();
void rent_revenue();
void Exit_Page();
void Mansarover();
void Vaishali();
void Jhotwara();
char ch;
int flag=0;

void LoginPage()
{
    system("cls");
    Heading();
    char username[20],pass[20],ori_username[20]="ComputerProject",ori_pass[20]="iiitvadodara";
    int count=0;
    do
    {
       printf("\n\n\n\t\t\tEnter your login credentials :-----------");
       printf("\n\n\t\t\t\tUsername : ");
       scanf("%s",&username);
       printf("\n\t\t\t\tPassword : ");
       scanf("%s",&pass);
       if(strcmp(username,ori_username)==0 && strcmp(pass,ori_pass)==0)
       {
           printf("\n\n\t\t\t\t\tLogin Successful-------");
           printf("\n\t\tEnter any key to continue------");
           getch();
           system("cls");
           Second_Page();
           break;
       }
       else
       {
           printf("\n\n\t\t\t\tInvalid Input------Try Again.");
           printf("\n\t\t\t\tPress any key to continue---");
           count++;
           getch();
           system("cls");
           Heading();
       }
    }while(count<=4);
    if(count>4)
    printf("\n\n\t\tTime Out----------Account Blocked.");
}
