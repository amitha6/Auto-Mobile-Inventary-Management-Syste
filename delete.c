#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data
{
    char Product_name[100];
    char Company_name[100];
    char Price[20];
    char Warranty[20];
    char Quantity[20];
    char Model[40];
};
void utl(char s[])/*Upper case to lower case conversion*/
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
void delete()
{
    FILE*fp;
    FILE*ft;
    int a;
    int i=0;
    int j;
    struct data store;
    struct data temp;
    
    fp=fopen("automobile_database.txt","r");
    if(fp==NULL)
    {
        printf("File not accessed");
        return;
    }
    do
    {
        fscanf(fp,"%s     %s     %s     %s     %s     %s",store.Product_name,store.Company_name,store.Price,store.Warranty,store.Quantity,store.Model);
        i++;
    } 
    while(!feof(fp));
    
    printf("1.To delete a product with specified company name.\n2.To delete products with specified warranty\n0.To quit\n");
    printf("\nEnter a number to perform the operation : ");
    scanf("%d",&a);
    while(1)
    {
        if(a!=1 && a!=0 && a!=2)
        {
            printf("Enter a valid option:");
            scanf("%d",&a);
        }
        else
        {
            break;
        }
    }
   
    fseek(fp,0,SEEK_SET);             
    if(a==1)
    {
        char input1[20];
        char input2[20];
        int k=0;
        while (1)
        {
            printf("\nEnter Product name : ");
            scanf("%s",input1);
            utl(input1);
            printf("Enter Company name : ");
            scanf("%s",input2);
            utl(input2);
            k=0;
            fseek(fp,0,SEEK_SET);
            do
            {
                k++;
                if(k>i)
                {
                    break;
                }
                fscanf(fp,"%s     %s     %s     %s     %s     %s",store.Product_name,store.Company_name,store.Price,store.Warranty,store.Quantity,store.Model);
                strcpy(temp.Product_name,store.Product_name);
                utl(store.Product_name);
                utl(temp.Product_name);
                strcpy(temp.Company_name,store.Company_name);
                utl(temp.Company_name);
                utl(store.Company_name);
            }
            while(strcmp(input1,temp.Product_name)!=0 || strcmp(input2,temp.Company_name)!=0 ); 
            if(strcmp(input1,store.Product_name)==0 && strcmp(input2,store.Company_name)==0)
            {
                printf("\nThe specified item is deleted successfully.\n");
                break;
            }
            if(k>i)
            {
                printf("\nUnable to find the company or the product you entered\n");
                printf("Please enter a valid company and product name\n");
            }
                
        }
        fseek(fp,0,SEEK_SET);   
        ft=fopen("temp.txt","a");
        for(j=0;(j<i-1) && (!feof(fp));++j)
        {
            fscanf(fp,"%s     %s     %s     %s     %s     %s",store.Product_name,store.Company_name,store.Price,store.Warranty,store.Quantity,store.Model);
            strcpy(temp.Company_name,store.Company_name);
            utl(temp.Company_name);
            if(strcmp(input2,temp.Company_name)!=0)
            {
                fprintf(ft,"%s     %s     %s     %s     %s     %s\n",store.Product_name,store.Company_name,store.Price,store.Warranty,store.Quantity,store.Model);
            }
        }
    }
    fseek(fp,0,SEEK_SET);             
    if(a==2)
    {
        char input3[20];
        int k=0;
        while (1)
        {
            printf("Enter Warranty(in years) : ");
            scanf("%s",input3);
            k=0;
            fseek(fp,0,SEEK_SET);
            do
            {
                k++;
                if(k>i)
                {
                    break;
                }
                fscanf(fp,"%s     %s     %s     %s     %s     %s",store.Product_name,store.Company_name,store.Price,store.Warranty,store.Quantity,store.Model);
            }
            while(strcmp(input3,store.Warranty)!=0); 
            if(strcmp(input3,store.Warranty)==0)
            {
                printf("\nThe products with specified warranty have been successfully deleted.\n");
                break;
            }
            if(k>i)
            {
                printf("No product found with the given warranty\nEnter a");
            } 
        }
        fseek(fp,0,SEEK_SET);   
        ft=fopen("temp.txt","a");
        for(j=0;(j<i-1) && (!feof(fp));++j)
        {
            fscanf(fp,"%s     %s     %s     %s     %s     %s",store.Product_name,store.Company_name,store.Price,store.Warranty,store.Quantity,store.Model);
            //if((strcmp(input1,store.Product_name)!=0) && (strcmp(input2,store.Company_name)!=0))
            if(strcmp(input3,store.Warranty)!=0)
            {
                fprintf(ft,"%s     %s     %s     %s     %s     %s\n",store.Product_name,store.Company_name,store.Price,store.Warranty,store.Quantity,store.Model);
            }
        }
    }
    if(a==0)
    {
        return;
    }
    fclose(fp);
    fclose(ft);
    
    remove("automobile_database.txt");
    rename("temp.txt","automobile_database.txt");
    
}
