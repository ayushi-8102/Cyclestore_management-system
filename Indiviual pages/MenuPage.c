#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void MenuPage()
{
  system("cls");
  Sales_Heading();
  int choice;
  printf("\n\n\n\t\t\t1. Add Customer Details.");
  printf("\n\t\t\t2. Customer's List.");
  printf("\n\t\t\t3. Update Costomer's List.");
  printf("\n\t\t\t4. Search Customer's.");
  printf("\n\t\t\t5. Delete Customer's.");
  printf("\n\t\t\t6. Total Revenue.");
  printf("\n\t\t\t7. Return to Home Page.");
  L:
  printf("\n\n\t\tChoose the Option-------");
  scanf("%d",&choice);
  switch(choice)
  {
      case 1: Add_Page();
      break;
      case 2: List_Page();
      break;
      case 3: Update_Page();
      break;
      case 4: Search_Page();
      break;
      case 5: Delete_Page();
      break;
      case 6: sales_revenue();
      break;
      case 7: Second_Page();
      default : printf("\n\n\t\tInvalid Input.----Try Again.");
      goto L;
  }
}