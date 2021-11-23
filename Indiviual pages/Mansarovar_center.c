#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
char ch; 

void Vaishali()
{
    char model[25];
    int quantity;
    D:
    system("cls");
    Centre_Heading();
    printf("\n\t\t\t---------------Vaishali Centre Details-------------");
    printf("\n\n\t\t\t\t1. Add new stock.");
    printf("\n\t\t\t\t2. Available Cycles.");
    printf("\n\t\t\t\t3. Update the Stock.");
    printf("\n\t\t\t\t4.Return to previous page.");
    printf("\n\n\t\tEnter Your Choice-- :");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1: E:
            system("cls");
        Centre_Heading();
        FILE *p1;
        p1=fopen("Vais.txt","a");
        printf("\n\t\t\t----------------------Vaishali Centre Details----------------------");
        printf("\n\n\t\t\t+++++++++++++++Add New Stock+++++++++++++++++");
        printf("\n\n\t\t\tEnter Model No : ");
        scanf("%s",model);
        for(int i=0;i<strlen(model);i++)
        {
            model[i]=toupper(model[i]);
        }
        printf("\n\t\t\tEnter Quantity : ");
        scanf("%d",&quantity);
        fprintf(p1,"%s %d \n",model,quantity);
        fclose(p1);
        printf("\n\n\t\tDetails Has Been Successfully Added---");
        printf("\n\n\t\tDo You Want To Add More---[Y/N] : ");
        F:
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        {
            goto E;
        }
        else if(ch=='n' || ch=='N')
        {
            goto D;
        }
        else
        {
            printf("\n\n\t\tInvalid Input-----Enter Again :");
            goto F;
        }
        break;

        case 2: system("cls");
        Centre_Heading();
        int num=0;
        FILE *p2;
        p2=fopen("Vais.txt","r");
        printf("\n\t\t\t----------------------Vaishali Centre Details----------------------");
        printf("\n\n\t\t=======================Available Cycles======================");
        printf("\n\n\t\t\t%-20s%-10s","Model Number","Quantity");
        while(fscanf(p2,"%s %d",model,&quantity)!=EOF)
        {
            printf("\n\t\t\t %-20s%-10d",model,quantity);
            num=num+quantity;
        }
        printf("\n\t\t---------------------------------");
        printf("\n\t\tTotal Number of Cycles : %d",num);
        printf("\n\n\tPress any key to continue--- ");
        getch();
        fclose(p2);
        goto D;
        break;

        case 3: system("cls");
        Centre_Heading();
        char mod[25];
        FILE *p3,*p4;
        p3=fopen("Vais.txt","r");
        p4=fopen("temp_Vais.txt","w+");
        printf("\n\t\t\t----------------------Vaishali Centre Details----------------------");
        printf("\n\n\t\t=======================Update The Stock======================");
        printf("\n\n\t\t\tEnter The Model No. To Update : ");
        scanf("%s",mod);
        for(int i=0;i<strlen(mod);i++)
        {
            mod[i]=toupper(mod[i]);
        }
        while(fscanf(p3,"%s %d",model,&quantity)!=EOF)
        {
            if(strcmp(mod,model)==0)
            {
                printf("\n\n\t\t-----Existing Stock-----");
                printf("\n\n\t\t\t%-20s%-10s","Model Number","Quantity");
                printf("\n\t\t\t %-20s%-10d",model,quantity);
                printf("\n\n\t\t\tEnter New Stock :-");
                printf("\n\n\t\t\t\tModel No : ");
                scanf("%s",model);
                for(int i=0;i<strlen(model);i++)
                {
                    model[i]=toupper(model[i]);
                }
                printf("\n\t\t\t\tQuantity : ");
                scanf("%d",&quantity);
                fprintf(p4," %s %d ",model,quantity);
                printf("\n\n\t\tData Updated Successfully");
                n=10;
            }
            else
            {
                fprintf(p4," %s %d ",model,quantity);
            }
        }
        if(n!=10)
        {
            printf("Data Not Found---");
        }
        fclose(p3);
        fclose(p4);
        remove("Vais.txt");
        rename("temp_Vais.txt","Vais.txt");
        getch();
        goto D;
        break;

        case 4: Centre_Menu();
        break;

        default: printf("\n\n\tInvalid Input----- ");
        printf("\n\n\tPress any key to enter again : ");
        getch();
        goto D;
    }
}