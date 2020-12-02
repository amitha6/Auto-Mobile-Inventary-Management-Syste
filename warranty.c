#include<stdio.h>
#include<stdlib.h>
void warranty()
{
	struct inventory
	{
		char Product_name[25];
		char Company_name[25];
		char Price[10];
		char Warranty[10];
		int Qty_avai;
		char Model_no[20];
	}Items[100];
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
	
	int number;
	float n,n1,n2;

	while (1)
	{        
		printf("Enter 1 to find the products less that the given warranty\n");
		printf("Enter 2 to find the products greater than the given warranty\n");
		printf("Enter 3 to find the products equal to the given warranty\n");
		printf("Enter 4 to find the products between the given warranty range\n");
		scanf("%d",&number);
		if(number==1 || number==2 || number==3)
		{
			printf("\nEnter the value of warranty(in years) : ");
			scanf("%f",&n);
			for(j=0;j<i-1;j++)
			{
				if(number==1)
				{
			        	if(n>atof((Items[j].Warranty)))
			        	{
				        	count++;  
				        	printf("\n%d.Product : %s\nCompany Name : %s\nWarrenty: %s\n",count,Items[j].Product_name,Items[j].Company_name,Items[j].Warranty);
			        	}
				}	
				if(number==2)
				{
					if(n<atof((Items[j].Warranty)))
					{
						count++;
                        			printf("\n%d.Product : %s\nCompany Name : %s\nWarrenty: %s\n",count,Items[j].Product_name,Items[j].Company_name,Items[j].Warranty);
                    			}
				}
				if(number==3)
				{
                    			if(n==atof((Items[j].Warranty)))
					{
                        			count++;
                        			printf("\n%d.Product : %s\nCompany Name : %s\nWarrenty: %s\n",count,Items[j].Product_name,Items[j].Company_name,Items[j].Warranty);
                    			}
                		}
			}
			if(number==1 && count==0){
				printf("There are no products less than the specified warrenty");
			}
			else if(number==2 && count==0){
                		printf("There are no products greater than the specified warrenty");
			}
			else if(number==3 && count==0){
				printf("There are no products equal to the specified warrenty");
			}
			break;
		}
		else if(number==4)
		{
           		printf("Enter the lower limit of warrenty(in years) : ");
           		scanf("%f",&n1);
           		printf("Enter the upper limit of warrenty(in years) : ");
           		scanf("%f",&n2);
           		for(j=0;j<i-1;j++)
			{
                 		if(n1<atof(Items[j].Warranty) && n2>atof(Items[j].Warranty))
                    		{
			 		count++;  
			 		printf("\n%d.Product : %s\nCompany Name : %s\nWarrenty: %s\n",count,Items[j].Product_name,Items[j].Company_name,Items[j].Warranty);
	           		}
             		}
         		if(number==4 && count==0)
			{
             			printf("There are no products in the range of specified warrenty");
          		}
         		break; 
		}
		else
		{
			printf("\nPlease enter valid option\n");
		}
	}
fclose(fp);
}
/*int main()
{
	warranty();
	return 0;
}*/
