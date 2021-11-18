#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void cycle_record()
{
    FILE *f;
    f = fopen("add.txt","r");

    if(f == NULL) {
        printf("Unable to open the file");
        exit(1);
    }
    char modelnumber[25],firstname[25],lastname[25],address[25],phonenumber[25],nationality[25],email[25];
    unsigned int period;
    system("cls");
    Rent_Heading();
	printf("\n\n\n%-15s%-25s%-20s%-20s%-20s%-33s%-20s\n","Model No","Full Name", "Address", "Phone No", "Nationality", "Email", "Period(hours)");
    for(int i=0;i<140;i++)
	{
		printf("-");
	}
    printf("\n");
    while(fscanf(f,"%s %s %s %s %s %s %s %u\n", modelnumber, firstname, lastname, address, phonenumber, nationality, email, &period)!=EOF)
    {
        char space[5]=" ";
        strncat(firstname,space,sizeof(firstname)-sizeof(space)-1);
        strncat(firstname,lastname,sizeof(firstname)-sizeof(lastname)-1);
        printf("%-15s%-25s%-20s%-20s%-20s%-33s%-20u\n", modelnumber, firstname, address, phonenumber, nationality, email, period);
    }
    printf("\n");
    for(int i=0;i<140;i++)
	{
		printf("-");
	}
    printf("\n");
    fclose(f);
    getch();
    Rent_Menu();
}