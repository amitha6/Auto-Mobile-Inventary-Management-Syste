#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data
{
    char Product_name[100];
    char Company_name[100];
    char Price[20];
    char Warranty[20];
    char Qty_avai[20];
    char Model_no[40];
};

void tolow(char s[])
{
    int c=0;
    while(s[c])
    {
        if(s[c]>='A' && s[c]<='Z')
        {
            s[c]=s[c]+32;
        }
        c++;
    }
}

void modify()
{
    FILE*fp;
    fp=fopen("automobile_database.txt","r");
    if(fp==NULL)
    {
        printf("\n Error cannot open file");
        return;
    }
    struct data temp;
    struct data temp_lower;
    struct data temp1;
    //struct data temp1_lower;
    char temp_product_name[100];
    char temp_company_name[100];
   
    int number,i=0,k=0;

    do
    {
        fscanf(fp,"%s     %s     %s     %s     %s     %s",temp.Product_name,temp.Company_name,temp.Price,temp.Warranty,temp.Qty_avai,temp.Model_no);
        i++;
    }
    while(!feof(fp));
    fseek(fp,0,SEEK_SET);
    while (1)
    {
        printf("\nEnter Product name : ");
        scanf("%s",temp_product_name);
        tolow(temp_product_name);
        printf("Enter Company name : ");
        scanf("%s",temp_company_name);
        tolow(temp_company_name);
        k=0;
        fseek(fp,0,SEEK_SET);
        do
        {
            k++;
            if(k>i)
            {
                break;
            }            
            fscanf(fp,"%s     %s     %s     %s     %s     %s",temp.Product_name,temp.Company_name,temp.Price,temp.Warranty,temp.Qty_avai,temp.Model_no);
            strcpy(temp_lower.Product_name,temp.Product_name);
            tolow(temp_lower.Product_name);
            strcpy(temp_lower.Company_name,temp.Company_name);
            tolow(temp_lower.Company_name);
            strcpy(temp_lower.Price,temp.Price);
            tolow(temp_lower.Price);
            strcpy(temp_lower.Warranty,temp.Warranty);
            tolow(temp_lower.Warranty);
            strcpy(temp_lower.Qty_avai,temp.Qty_avai);
            tolow(temp_lower.Qty_avai);
            strcpy(temp_lower.Model_no,temp.Model_no);
            tolow(temp_lower.Model_no);
        }
        while(strcmp(temp_lower.Company_name,temp_company_name)!=0 || strcmp(temp_lower.Product_name,temp_product_name)!=0 );  
        if(strcmp(temp_lower.Company_name,temp_company_name)==0 && strcmp(temp_lower.Product_name,temp_product_name)==0)
        {
            break;
        }
        if(k>i)
        {
            printf("\nUnable to find the company or the product you entered\n");
            printf("Please enter a valid company and product name\n");
        } 
    }
    
    
    printf("\nSelect an option:");
    printf("\nEnter 1 to modify Price");
    printf("\nEnter 2 to modify Warranty");
    printf("\nEnter 3 to modify Quantity Available");
    printf("\nEnter 4 to EXIT");
    printf("\n");
    scanf("%d",&number);

    while(1)
    {
        if(number!=1 && number!=2 && number!=3 && number!=4)
        {
            printf("\nEnter a valid option\n");
            scanf("%d",&number);
        }
        else
        {
            break;
        }
    }
    
    switch (number)
    {
        case 1:
            printf("\nCurrent price : Rs %s",temp.Price);
            printf("\nEnter new price\n");
            scanf("%s",temp.Price);
            break;
        case 2:
            printf("\nCurrent Warranty : %s",temp.Warranty);
            printf("\nEnter new warranty\n");
            scanf("%s",temp.Warranty);
            break;
        case 3:
            printf("\nCurrent quantity available : %s",temp.Qty_avai);
            printf("\nEnter new quantity available\n");
            scanf("%s",temp.Qty_avai);
            break;
        case 4:
            return;
    }
    printf("\nYour changes have been modified successfully\n");
    fclose(fp);
    fp=fopen("automobile_database.txt","r");
    FILE*fp1;
    fp1=fopen("automobile_database1.txt","a");
    int j=0;
    
    for(j=0;j<i-1 && !feof(fp);j++)
    {
        fscanf(fp,"%s     %s     %s     %s     %s     %s",temp1.Product_name,temp1.Company_name,temp1.Price,temp1.Warranty,temp1.Qty_avai,temp1.Model_no);
        if(strcmp(temp1.Product_name,temp.Product_name)==0 && strcmp(temp1.Company_name,temp.Company_name)==0)
        {    
	        fprintf(fp1,"%s     %s     %s     %s     %s     %s\n",temp.Product_name,temp.Company_name,temp.Price,temp.Warranty,temp.Qty_avai,temp.Model_no);
        }
        else
        {
	        fprintf(fp1,"%s     %s     %s     %s     %s     %s\n",temp1.Product_name,temp1.Company_name,temp1.Price,temp1.Warranty,temp1.Qty_avai,temp1.Model_no);
        }        
    }
    
    fclose(fp);
    fclose(fp1);
    remove("automobile_database.txt");
    rename("automobile_database1.txt","automobile_database.txt");
}
