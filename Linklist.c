#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "test.h"
#include "Array.c"
/**
    @file Linkedlist.c
    @author Nilson Xavier da Luz 0838753 & Samuel Cheung 0836752
*/

 /**
    @brief Dit is een struct die een lijst creeërd
    @param iValue dit is de ingevulde nummer
    
    */

struct data_struct* create_list(int iValue)
    {
        struct data_struct *pPtr = (struct data_struct*)&myarray[iNumber];
        if(NULL == pPtr)
            {
                printf("\n Node creation failed \n");
                return NULL;
            }
        
        pPtr->flag=-1;
        pPtr->size=(int)log10(iValue)+1;;
        pPtr->iValue=iValue;
        pPtr->next = NULL;
        pPtr -> lastflag = -1;
        pHead = pPtr;
        iNumber=iNumber+search_flag(iNumber);
       
        return pPtr;
    }
 /**
    @brief Dit is een struct die een ingevulde waarde in een lijst plaats. Als er geen lijst is wordt eerst de lijst gemaakt.
    @param iValue dit is de ingevulde nummer
    @param add_to_end dit is om de waarde aan de einde van de lijst te zetten
    */



struct data_struct* add_to_list(int iValue, bool add_to_end) // toevoegen aan de list
{
    iSize_data =0;
    iFull =0;
    if(NULL == pHead)
        {
            return (create_list(iValue));
        }
    
    //iCounter =0;
    check_array();
    printf("%d\n",iSize_data );
   
    struct data_struct *pPtr = (struct data_struct*)&myarray[iSize_data];
    if(NULL == pPtr)
        {
            printf("\n Node creation failed \n");
            return NULL;
        }
        
    if (iFull>(MAX-1))  // Als het geheugen vol zit wordt het naar de database verstuurd
        {
            saving (iValue);
            
        }
    else
        {
            pPtr->flag=-1;
            pPtr->size=(int)log10(iValue)+1;;
            pPtr->iValue= iValue;
            pPtr->next = NULL;
            pPtr->next = pHead;
            pPtr -> lastflag = -1;
            pHead = pPtr;
            iNumber=iNumber+  search_flag(iSize_data);
   
   
            return pPtr;
        }   
                             
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

    //printf("\nSearching the list for iValue %d \n",iValue);

    while(pPtr != NULL)
        {
           // printf("pointer: %d\n",pPtr->iValue );
            //printf("iValue: %d\n",iValue );

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
            if(pPrev)
              {
                *pPrev = pTmp;
              }
                       
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
    replace_array(iValue,pNum);
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

    printf("\nDeleting Value %d from list\n",iValue);

    pDel = search_in_list(iValue,&pPrev);
    

    if(pDel == NULL)
        {
            return -1;
        }
    else
        {
            
            if(pPrev != NULL)
                {
                    pPrev->next = pDel->next;
                }

            if(pDel == pCurr)
                {
                    pCurr = pPrev;
                }
            else if(pDel == pHead)
                {
                    pHead = pDel->next;
                }
        }


    del_array(pDel);
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
