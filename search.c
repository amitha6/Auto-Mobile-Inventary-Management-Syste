#include<stdio.h>
#include<string.h>
struct Item
{
  char Product_name[100];
  char Company_name[100];
 	char Price[20];
  char Warranty[20];
  char Quantity_available[20];
  char Model_number[70];
};
	void upper_con(char *str)
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
	void search()
	{
		char ch,product[100];
		int count=0,count1=0;
		printf("Enter the product : ");
		scanf("%s",product);
		FILE *fp;
		fp=fopen("automobile_database.txt","r");
		do
		{
			while((ch=fgetc(fp))!='\n'&&ch!=EOF)
			{
			  continue;
			}
			count++;
		}
		while(ch=='\n');
		fclose(fp);
		struct Item array[count];
		fp=fopen("automobile_database.txt","r");
		for(int i=0;i<count;i++)
		{
 			fscanf(fp,"%s %s %s %s %s %s",array[i].Product_name,array[i].Company_name,array[i].Price,array[i].Warranty,array[i].Quantity_available,array[i].Model_number);
		}
		for (int i=0;i<count;i++)
		{
 			upper_con(product);
 			upper_con(array[i].Product_name);
 			if (strcmp(array[i].Product_name,product)==0) 
  		{
   			count1=10;
   			printf("\nProduct_name : %s\nCompany_name : %s\nPrice : %s\nWarranty : %s\nQuantity : %s\nModel_number :  %s\n",array[i].Product_name,array[i].Company_name,array[i].Price,array[i].Warranty,array[i].Quantity_available,array[i].Model_number);
  		}
		}
		if(count1==0)
		{
			printf("\nSORRY!!..specified product is unavailable.\n");
		}
		fclose(fp);
	}

