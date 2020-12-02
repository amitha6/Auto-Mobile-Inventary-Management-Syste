#include<stdio.h>
void quantity()
{
	struct inventory
	{
		char Product_name[25];
		char Company_name[25];
		char Price[10];
		char Warranty[10];
		int Qty_avai;
		char Model_no[20];
	} Items[100];
	FILE *fp;
	fp = fopen("automobile_database.txt","r");
	int i=0,j;
	int count=0;
	char ch;
	char *tem;
	while((ch=fgetc(fp))!=EOF)
	{
		fseek(fp,-1,SEEK_CUR);
		fscanf(fp,"%s %s %s %s %d %s", Items[i].Product_name, Items[i].Company_name, Items[i].Price, (Items[i].Warranty), &(Items[i].Qty_avai), Items[i].Model_no);
		fgets(tem, 0, fp);
		i++;
	}
	int n;
	while(1)
	{
		printf("\nEnter the value of the quantity:");
		scanf("%d",&n);
		printf("\nThe products and their companies with quantity less than %d:\n",n);
		for(j=0;j<i-1;j++)
		{
			
			if(n>(Items[j].Qty_avai))
			{
				count++;
				printf("\n%d.Product : %s\nCompany Name : %s\nQuantity : %d\n",count,Items[j].Product_name,Items[j].Company_name,Items[j].Qty_avai);
			}	
		}
		if(count<1)
		{
			printf("\nSorry!There are no products less than the quantity %d.\nTry Again\n",n);
		}
		else
		{
			break;
		}
	}
	fclose(fp);
}
/*int main()
{
	quantity();
	return 0;
}*/
