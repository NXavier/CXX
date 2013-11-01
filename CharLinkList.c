#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
    @file main.c
    @author Nilson Xavier da Luz 0838753 & Samuel Cheung 0836752
*/

 /**
    @brief structure
    */
struct test_struct
{
    int iValue;
    struct test_struct *next;
};


int iCounter=0;
//char myarray[160000];
struct test_struct *pHead = NULL;
struct test_struct *pCurr = NULL;

 /**
    @brief Dit is een struct die een lijst creeërd
    @param iValue dit is de ingevulde nummer
    
    */

struct test_struct* create_list(int iValue)
{
    
    struct test_struct *pPtr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == pPtr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    
    pPtr->iValue=iValue;
    pPtr->next = NULL;
    pHead = pPtr;
    //mymalloc();
    return pPtr;
}
 /**
    @brief Dit is een struct die een ingevulde waarde in een lijst plaats. Als er geen lijst is wordt eerst de lijst gemaakt.
    @param iValue dit is de ingevulde nummer
    @param add_to_end dit is om de waarde aan de einde van de lijst te zetten
    */

struct test_struct* add_to_list(int iValue, bool add_to_end)
{
    if(NULL == pHead)
    {
        return (create_list(iValue));
    }
    
    struct test_struct *pPtr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == pPtr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
   
    pPtr->iValue= iValue;
    pPtr->next = NULL;
    pPtr->next = pHead;
    pHead = pPtr;
   
    return pPtr;
}

 /**
    @brief Dit is een struct die naar de de invulde iValue zoekt en teruggeeft.
    @param iValue dit is de ingevulde nummer

    */
struct test_struct* search_in_list(int iValue, struct test_struct **pPrev)
{
    struct test_struct *pPtr = pHead;
    struct test_struct *pTmp = NULL;
    bool found = false;

    printf("\n Searching the list for iValue %d \n",iValue);

    while(pPtr != NULL)
    {
        printf("pointer: %d\n",pPtr->iValue );
        printf("iValue: %d\n",iValue );

        if(pPtr->iValue==iValue)
        {
            found = true;
            break;
        }
        else
        {
            pTmp = pPtr;
            pPtr = pPtr->next;
        }
    }

    if(true == found)
    {
        printf("found\n");
        if(pPrev)
            printf("je zit in pPrev\n");
            printf("%d\n", pTmp);
            *pPrev = pTmp;
            printf("%d\n", *pPrev );
        return pPtr;
    }
    else
    {
        printf("NOT found\n");
        return NULL;
    }
}

 /**
    @brief In deze methode wordt een gevonden waarde vervangen.
    @param iValue dit is de ingevulde nummer
    @param num dit is de vervangende nummer
    */
int replace_number(int iValue,int pNum)
{
    struct test_struct *pPrev = NULL;
    struct test_struct *pReplace = NULL;

    printf("\n Deleting iValue %d from list\n",iValue);

    pReplace = search_in_list(iValue,&pPrev);
    
    if(pReplace == NULL)
    {
        return -1;
    }
    else
    {
        pReplace->iValue= pNum;
    }
    pReplace = NULL;

    return 0;
}
 /**
    @brief In deze methode wordt de gevonden waarde verwijderd.
    @param iValue dit is de ingevulde nummer
    */
int delete_from_list(int iValue)
{
    struct test_struct *pPrev = NULL;
    struct test_struct *pDel = NULL;

    printf("\n Deleting iValue %d from list\n",iValue);

    pDel = search_in_list(iValue,&pPrev);

    if(pDel == NULL)
    {
        return -1;
    }
    else
    {
        if(pPrev != NULL)
            pPrev->next = pDel->next;

        if(pDel == pCurr)
        {
            pCurr = pPrev;
        }
        else if(pDel == pHead)
        {
            pHead = pDel->next;
        }
    }

    free(pDel);
    pDel = NULL;

    return 0;
}

 /**
    @brief Deze methode print de linked list uit
    */
void print_list(void)
{
    struct test_struct *pPtr = pHead;

    printf("\n -------Printing list Start------- \n");

    while(pPtr != NULL)
    {
        printf("\n %d \n",pPtr->iValue);
        pPtr = pPtr->next;
    }
    printf("\n -------Printing list End------- \n");

    return;
}
 /**
    @brief Deze methode sorteert de linked list.
    */
void sort_list(void)
{
    struct test_struct *pPtr = pHead;
    int iTemp;

    while(pPtr != NULL)
    {
        if(pPtr->next == 0)
        {
            printf("End of List\n");
            return;
        }
        else
        {   
            if(pPtr->iValue >= pPtr->next->iValue)
            {   
                iTemp = pPtr-> iValue;
                pPtr->iValue = pPtr->next->iValue;
                pPtr->next->iValue = iTemp;
            }
            else
            {
                printf("%d is higher than %d \n", pPtr->next->iValue, pPtr->iValue );
            }
        }
        pPtr = pPtr->next;
    }
    return;
}

// void mymalloc(void)
// {
//     int i;

//     for(i=0;i<=20;i++)
//     {
//         printf("%d\n", i );
//         printf("%d\n", myarray[i]);
//     }
// }
 
 /**
    @brief De main weergeeft de interface aan waar de gewenste keuzes gemaakt kunnen worden.
    */
int main(void)
{
    int i = 0;
    int iInfo;
    int iNewnum;
    struct test_struct *pPtr = NULL;

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
            sort_list();
            sort_list();
            break;
        }
    }
    return 0;
}
