#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "test.c"

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
    printf("hello\n");
    //struct data_struct *pPtr = NULL;

    printf("Press 1 for add a number \n");
    printf("Press 2 to delete a number \n");
    printf("Press 3 for print list\n");
    printf("Press 4 to replace a number\n");
    printf("Press 5 to sort the list\n");

    while (true)
    {
        printf("Press a number\n");
        scanf("%d", &iInfo);
        
        switch (iInfo)
        {
            case 1:
            printf("Add a number...\n" );
            scanf("%d", &iInfo);
            add_to_list(iInfo,true);
            break;

            case 2:
            printf("Delete number\n" );
            scanf("%d", &iInfo);
            delete_from_list(iInfo);
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
           
            #pragma omp parallel
         
               #pragma omp for
               for(iSortCount=0;iSortCount<=100;iSortCount++)
               {
                   sort_list();
               }
             }

            break;
        }
    }
    return 0;
}
