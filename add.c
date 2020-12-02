#include <stdio.h>
#include <stdlib.h>

void Add()
{
	struct data{
		char Product_name[100];
		char Company_name[100];
		char Price[20];
		char Warranty[20];
		char Qty_avai[20];
		char Model_no[40];
	}Item;	
	FILE *fp;
	fp = fopen("automobile_database.txt","a");
	printf("Enter Product name : ");
	scanf("%s", Item.Product_name);
	printf("Enter Company name : ");
	scanf("%s", Item.Company_name);
	printf("Enter Price of the product : ");
	scanf("%s", Item.Price);
	printf("Enter Warranty of the product : ");
	scanf("%s", Item.Warranty);
	printf("Enter number of items available : ");
	scanf("%s", Item.Qty_avai);
	printf("Enter Model no : ");
	scanf("%s", Item.Model_no);
	fprintf(fp, "%s     %s     %s     %s     %s     %s\n", Item.Product_name, Item.Company_name, Item.Price, Item.Warranty, Item.Qty_avai, Item.Model_no);
	fclose(fp);
	printf("\nThe new product is successfully added\n");
}

/*int main()
{
	Add();
	return 0;
}*/


