/* RG PAINTS */

#include<stdio.h>
#include<string.h>
#include"shopHeader.h"
// main function
int main()
{
    int choice;
     printf("\n***********************************************************************************************************************\n");
     printf("\n***********************************************************************************************************************\n");
     printf("\n*************************************** RG PAINTS Shop Management System***********************************************\n");
     printf("\n***********************************************************************************************************************\n");
     printf("\n***********************************************************************************************************************\n");

     printf("1. Insert Record\t");
     printf("2. Search Records\t");
     printf("3. View Record\t");
     printf("4. Edit Record\t");
     printf("5. Delete Record\t");
     printf("6. Exit\t");

    do{
       
        printf("\n\n Enter your choice: ");
        fflush(stdin);


        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                insertData();
                break;

            case 2:
                searchData();
                break;

            case 3:
                viewData();
                break;
                
            case 4:
                editData();
                break;

            case 5:
                 DeleteData();
                 break;    

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    fclose(fp);
return 0;
}
    

