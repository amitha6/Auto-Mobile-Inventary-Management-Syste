#include<stdio.h>
#include"view.h"
#include"modify.h"
#include"search.h"
#include"delete.h"
#include"add.h"
#include"sorting_price.h"
#include"quantity.h"
#include"warranty.h"

int main()
{
	printf("WELCOME TO C AUTOMOBILE INVENTORY MANGEMENT DATABASE!\n\n");
	while(1)
	{
		printf("Main Menu:\n");
		printf("----------\n");
		printf("1.Display all the Products with company names and their parameters.\n");
		printf("2.Display the parameters of the specified Product.(search)\n");
		printf("3.Display the items with prices of the specified product in sorted order or in a given range.\n");
		printf("4.Display the products with warranty less than or greater than or equal to given value or in a given range.\n");
		printf("5.Display the products with quantity less than given value.\n");
		printf("6.Add an item.\n");
		printf("7.Delete an item or items with specified warranty.\n");
		printf("8.Modify a parameter.\n");
		printf("9.Quit the program.\n");
		int n;
		printf("\nChoose a number to perform the corresponding action : ");
		scanf("%d",&n);
		FILE *fp;
		char m;
		switch(n)
		{
			case 1:
				printf("\nYou have chosen to view all the parameters.\n\n");
				fp = fopen("automobile_database.txt","r");
				view(fp);
				fclose(fp);
				break;
			case 2:
				printf("\nYou have chosen to search a specified item.\n");
				search();
				break;
			case 3:
				printf("\nYou have chosen to display the items with prices of a specified product in sorted order or in a given range.\n");
				Sort_Price();
				break;
			case 4:
				printf("\nYou have chosen to display the products with warranty less than or greater than or equal to given value or in a given range.\n");
				warranty();
				break;
			case 5:
				printf("\nYou have chosen to display the products with quantity less than given value.\n");
				quantity();
				break;
			case 6:
				printf("\nYou have chosen to add an item.\n");
				Add();
				break;
			case 7:
				printf("\nYou have chosen to delete an item or items of  specified warranty.\n");
				delete();
				break;
			case 8:
				printf("\nYou have chosen to modify a parameter\n");
				modify();
				break;
			case 9:
				printf("\nProgram is terminated as you have chosen to quit.\n");
				return 0;
			default:
				printf("Enter Valid Option.\n");

		};
		printf("\n");
		printf("\n");
	}

	return 0;
}
