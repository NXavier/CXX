#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 /**
    @brief structure
    */

struct data_struct
{
    int iValue;
    struct data_struct *next;
};

int iCounter=0;
//char myarray[160000];
struct data_struct *pHead = NULL;
struct data_struct *pCurr = NULL;

 /**
    @brief Dit is een struct die een lijst creeërd
    @param iValue dit is de ingevulde nummer
    
    */

struct data_struct* create_list(int iValue)
{
    
    struct data_struct *pPtr = (struct data_struct*)malloc(sizeof(struct data_struct));
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

struct data_struct* add_to_list(int iValue, bool add_to_end)
{
    if(NULL == pHead)
    {
        return (create_list(iValue));
    }
    
    struct data_struct *pPtr = (struct data_struct*)malloc(sizeof(struct data_struct));
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
struct data_struct* search_in_list(int iValue, struct data_struct **pPrev)
{
    struct data_struct *pPtr = pHead;
    struct data_struct *pTmp = NULL;
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
    struct data_struct *pPrev = NULL;
    struct data_struct *pReplace = NULL;

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
    struct data_struct *pPrev = NULL;
    struct data_struct *pDel = NULL;

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
    struct data_struct *pPtr = pHead;

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
    struct data_struct *pPtr = pHead;
    int iTemp;

    while(pPtr != NULL)
    {
        if(pPtr->next == 0)
        {
            //printf("End of List\n");
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
        }
        pPtr = pPtr->next;
    }
    return;
}