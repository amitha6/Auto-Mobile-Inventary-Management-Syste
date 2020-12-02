#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Upper_con(char *str);
void Sort_Price()
{
	struct inventory{
		char Product_name[100];
		char Company_name[100];
		int Price;
		char Warranty[20];
		char Qty_avai[20];
		char Model_no[40];
	};
	struct inventory Items[200];
	struct inventory Pro_type[20];
	struct inventory temp;
	char tem_str1[20], tem_str2[20], Product[20];
	int i, ch, opt;
	int Low_lim, Upp_lim;
	char *tem;
	printf("Enter Product name : ");
	scanf("%s", Product);
	FILE *fp;
	fp = fopen("automobile_database.txt","r");
	for(i=0; (ch = fgetc(fp)) != EOF; i++)
	{
		fseek(fp, -1, SEEK_CUR);
		fscanf(fp, "%s     %s     %d     %s     %s     %s", Items[i].Product_name, Items[i].Company_name, &(Items[i].Price), Items[i].Warranty, Items[i].Qty_avai, Items[i].Model_no);
		fgets(tem, 0, fp); 
	}
	int k = i;
	int count=0, j=0, r=0, index[20];
	for(i=0; i<k; i++)
	{
		strcpy(tem_str1, Items[i].Product_name);
		Upper_con(Product);
		Upper_con(tem_str1);
		if(strcmp(Product, tem_str1) == 0)
		{
			count = 1;
			Pro_type[j] = Items[i];
			j++;									
		}
	}		
	if(count == 0)
	{
		printf("SORRY!!!\nPRODUCT IS UNAVAILABLE !!!");
	}
	else
	{
		int p,q,min;
		for(p=0; p<j-1; p++)
		{
			r++;
			min = p;
			for(q=p+1; q<j; q++)
			{
				if(Pro_type[q].Price < Pro_type[min].Price)
				{
					min = q;
				}
			}
			temp = Pro_type[min];
			Pro_type[min] = Pro_type[p];
			Pro_type[p] = temp;	
		}
		 
		printf("1: Display sorted price list for the entered product.\n2: Display the products having the price in the specified range.\n");
		printf("Choose your option : ");	
		scanf("%d", &opt); 
		if(opt == 1)
		{
			for(i=0; i<j; i++)
			{
	 			printf("\nProduct name : %s\n", Pro_type[i].Product_name);
        			printf("Company name : %s\n", Pro_type[i].Company_name);
          			printf("Price : Rs.%d/-\n",Pro_type[i].Price);
         			printf("Warranty : %s\n", Pro_type[i].Warranty);
         			printf("Qty available : %s\n", Pro_type[i].Qty_avai);
         			printf("Model number : %s\n", Pro_type[i].Model_no);
			}
		}
		else if(opt == 2)
		{
			int tem = 0;
			printf("Enter Lower Limit and Upper limit of the range\n");
			printf("Enter Lower Limit(in Rs.) : ");
			scanf("%d", &Low_lim);
			printf("Enter Upper Limit(in Rs.) : ");
			scanf("%d", &Upp_lim);
			for(i=0; i<j; i++)
			{
				if(Pro_type[i].Price >= Low_lim && Pro_type[i].Price <= Upp_lim)
				{
					tem = 1;
					printf("\nProduct name : %s\n", Pro_type[i].Product_name);
                			printf("Company name : %s\n", Pro_type[i].Company_name);
                			printf("Price : Rs.%d/-\n",Pro_type[i].Price);
                			printf("Warranty : %s\n", Pro_type[i].Warranty);
                			printf("Qty available : %s\n", Pro_type[i].Qty_avai);
                 			printf("Model number : %s\n", Pro_type[i].Model_no);
				}
			}
			if(tem == 0)
			{
				printf("\nThere are no products with the price in between given range.");
			}
		}
	}
}
void Upper_con(char *str)
{
	int i;
	char *ch;
	for(i=0; ((ch = (str + i))) && *ch != '\0'; i++)
	{
		if(*ch >= 97 && *ch <= 122)
		{
			*ch -= 32;
		}
	}
}
