struct shop
{
    // data 
    char company[100];
    char colorName[100];
    float price;
    float quantity;
}item,item1;

FILE *fp;
char fn[] = "shop.txt";

 // code for insert data.
void insertData()
{
   fp = fopen(fn,"ab");

   if(fp == NULL)
   {
    printf("\n Data not found.");
    return ;
   }
   
   int i,num;

   printf("\n How many company items do you want to insert:");
   scanf("%d",&num);

    printf("\n***********************************************************************************************************************\n");
    printf("\n*************************************************INSERT DATA***********************************************************\n");
    printf("\n***********************************************************************************************************************\n");
   
    for(i=0; i<num; i++)
    {
        printf("\n Enter Company name:");
        scanf("%s",item.company);

        printf("\n Enter ColorName:");
        scanf("%s",item.colorName);

        printf("\n Enter Quantity:");
        scanf("%f",&item.quantity);

        printf("\n Enter Price(in Rs.):");
        scanf("%f",&item.price);
        
        fwrite(&item, sizeof(struct shop),1,fp);
    }
    fclose(fp);
    printf("\n Item inserted succesfully.");
}

// code for search data.
void searchData()
{
    fp = fopen(fn,"rb");
    char sname[50];
    
    if(fp == NULL)
    {
        printf("\n File not found.");
        return ;
    }

    printf("\n Enter company name to be searched:");
    scanf("%s",sname);

    while(fread(&item,sizeof(struct shop),1,fp)>0)
    {
        if(strcmp(item.company,sname)==0)
        {
            printf("\n***********************************************************************************************************************\n");
            printf("\n***************************************************SEARCHED DATA*******************************************************\n");
            printf("\n***********************************************************************************************************************\n");

            printf("\n CompanyName: %s\n",item.company);
            printf("\n ColorName:%s\n",item.colorName);
            printf("\n Qunatity:%.2f\n",item.quantity);
            printf("\n Price(in Rs.):%.2f\n",item.price);
            return ;
        }
    }
    fclose(fp);
    printf("\n Data not found.");
}

// code for view data
void viewData()
{
   fp=fopen(fn,"rb+");
    
    if(fp == NULL)
    {
        printf("\n No Data to show.");
    }

    printf("\n***********************************************************************************************************************\n");
    printf("\n*************************************************VIEW DATA*************************************************************\n");
    printf("\n***********************************************************************************************************************\n");

   while(fread(&item,sizeof(struct shop),1,fp))
    {
            printf("\n CompanyName: %s\n",item.company);
            printf("\n ColorName:%s\n",item.colorName);
            printf("\n Qunatity:%.2f\n",item.quantity);
            printf("\n Price(in Rs.):%.2f\n",item.price);
    }
    fclose(fp);
}

// code for edit data
void editData()
{
    fp = fopen(fn,"r+b");
     
    char cp[100],cn[100];

    float qty,np;

    if(fp == NULL)
    {
        printf("\n The data is empty.");
        return ;
    }
     int update=0;

        printf("\n 1] company name.");
        printf("\n 2] color name.");
        printf("\n 3] quantity.");
        printf("\n 4] price.");
        printf("\n 5] All.");
        printf("\n what do you want to edit:");
        scanf("%d",&update);
        
        
        printf("\n Enter company name:");
        scanf("%s",cp);

   while(fread(&item, sizeof(struct shop),1,fp))
    { 
       
        if(strcmp(item.company,cp)==0)
        {

           switch(update)
            {
                case 1: printf("\n Enter new company name:");
                        scanf("%s",item.company);
                        fseek(fp,-sizeof(struct shop), SEEK_CUR);
                        fwrite(&item,sizeof(struct shop),1,fp);
                        break;

                case 2: printf("\n Enter new colorName:");
                        scanf("%s",item.colorName);
                        fseek(fp,-sizeof(struct shop), SEEK_CUR);
                        fwrite(&item,sizeof(struct shop),1,fp);
                        break;

                case 3: printf("\n Enter new quantity:");
                        scanf("%f",&item.quantity);
                        fseek(fp,-sizeof(struct shop), SEEK_CUR);
                        fwrite(&item,sizeof(struct shop),1,fp);
                        break;

                case 4: printf("\n Enter new price:");
                        scanf("%f",&item.price); 
                        fseek(fp,-sizeof(struct shop), SEEK_CUR);
                        fwrite(&item,sizeof(struct shop),1,fp);
                        break;

                case 5: printf("\n Enter new company name:");
                        scanf("%s",item.company);

                        printf("\n Enter new colorName:");
                        scanf("%s",item.colorName); 

                        printf("\n Enter new quantity:");
                        scanf("%f",&item.quantity);

                        printf("\n Enter new price:");
                        scanf("%f",&item.price);
                       
                        fseek(fp,-sizeof(struct shop), SEEK_CUR);
                        fwrite(&item,sizeof(struct shop),1,fp);
                        break;

                default: printf("\n Invalid choice.");                         
            }

         fseek(fp, -sizeof(struct shop), SEEK_CUR);
         fwrite(&item, sizeof(struct shop),1,fp);
         break;
        }
    } 
    fclose(fp);       
    printf("\n Data edited successfully.");
}

void DeleteData() 
{
    char cp[100];

    printf("Enter the Company name you want to Delete:");
    scanf("%s",cp);

    fp = fopen(fn, "rb");
    if(fp == NULL)
    {
        printf("\n Error opening file for reading.");
    }
    
    FILE *tempfile = fopen("temp1.txt", "wb");
    if(tempfile == NULL)
    {
        printf("\n Error creating temporary file.");
        fclose(fp);
        return ;
    }
    
    while(fread(&item1, sizeof(struct shop), 1, fp))
    { 
      if(strcmp(item1.company,cp)!=0) 
        { 
         fwrite(&item1, sizeof(struct shop), 1, tempfile);
        }
    }

    fclose(fp);
    fclose(tempfile);

    remove(fn);
    rename("temp1.txt",fn);
    printf("\n Record deleted successfully.");

}    
