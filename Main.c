#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "omp.h"
#include "test.h"
#include "Linklist.c"
#include "Database.c"
/**
    @file main.c
    @author Nilson Xavier da Luz 0838753 & Samuel Cheung 0836752
*/


 
 /**
    @brief De main weergeeft de interface aan waar de gewenste keuzes gemaakt kunnen worden.
    */
int main(void)
{
    int i = 0;
    int iInfo,iNewnum,iSortCount;
    
    struct data_struct *pPtr = NULL;
    printf("Geef een naam voor de database moet eindigen met .db\n");
    scanf("%s", &filename);
    //printf("%s\n", filename);
    while (true)
    {
       
        printf("\n--------------Commands------------- \n");
        printf("Press 1 for add a number \n");
        printf("Press 2 to delete a number \n");
        printf("Press 3 for print list\n");
        printf("Press 4 to replace a number\n");
        printf("Press 5 to sort the list\n");
        printf("Press 6 to print array list\n");
        printf("Press 7 to show memory\n");
        printf("Press 8 to print directly to database\n");
        printf("Press 9 to print numbers from text file to list\n");
        printf("\n----------------------------------- \n");
        printf("Press a number\n");
        scanf("%d", &iInfo);
        
        switch (iInfo)
        {
            case 1:
            printf("Add a number\n" );
            scanf("%d", &iInfo);
            printf("\n ");
            add_to_list(iInfo,true);
            printf("\n************** Memory ************ \n \n");

            printf("Beschikbaar: " );
            printf("%d",((MAX- memory_full()))*4 );
            printf(" bytes \n" );

            printf("Gebruikt: " );
            printf("%d",((MAX-(MAX- memory_full()))*4) );
            printf(" bytes \n" );
            printf("\n*********************************** \n \n");
            break;

            case 2:
            printf("Delete number\n" );
            scanf("%d", &iInfo);
            delete_from_list(iInfo);
            printf("\n************** Memory ************ \n \n");

            printf("Beschikbaar: " );
            printf("%d",((MAX- memory_full()))*4 );
            printf(" bytes \n" );

            printf("Gebruikt: " );
            printf("%d",((MAX-(MAX- memory_full()))*4) );
            printf(" bytes \n" );
            printf("\n*********************************** \n \n");
            break;

            case 3:
            print_list();
            break;

            case 4:
            printf("Enter the number you want to replace\n" );
            scanf("%d", &iInfo);
            printf("Enter a new number\n" );
            scanf("%d", &iNewnum);
            replace_number(iInfo,iNewnum);
            break;

            case 5: 
            printf("List is sorted press 3 to see the sorted list\n");
            #pragma omp parallel
            {
                #pragma omp for
                for(iSortCount=0;iSortCount<=MAX;iSortCount++)
                {
                    sort_list();
                }
            }
            break;
            case 6:
            print_linklist();
            break;

            case 7:
            printf("\n************** Memory ************ \n \n");

            printf("Beschikbaar: " );
            printf("%d",((MAX- memory_full()))*4 );
            printf(" bytes \n" );

            printf("Gebruikt: " );
            printf("%d",((MAX-(MAX- memory_full()))*4) );
            printf(" bytes \n" );
            printf("\n*********************************** \n \n");
            

            case 8:
            printf("Add a number to database\n" );
            scanf("%d", &iInfo);
            printf("\n");
            
            saving (iInfo);
            break;

            case 9:
            printf("Print numbers from text file to list\n");
            F2M();
            break;

            case 10:
            
            system("pause");
            return 0;
            break;
        }
    }
    return 0;
}
