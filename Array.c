#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "test.h"

/**
    @file array.c
    @author Nilson Xavier da Luz 0838753 & Samuel Cheung 0836752
*/

/**
    @brief Deze methde print alles van de memory uit
*/
void* print_linklist()
{
  

  for(iLijst=0;iLijst<=MAX-1;iLijst++)
   {
      printf("%d\t", iLijst );
      printf("%d\n", myarray[iLijst]);
   }

}

/**
    @brief Deze methode geeft de hoeveelheid memory aan dat gebruikt is
*/
int memory_full()
{
  int aantal=1;
  for(iLijst=0;iLijst<=MAX-1;iLijst++)
   {
    if (myarray[iLijst] != 0)
      {
        aantal++;
        if (aantal >(MAX-5))
        {
          aantal=MAX;
        }
      }
   }
   return aantal;

}
/**
    @brief Deze methode geeft de hoeveelheid memory aan dat gebruikt is
    @param iSize_data geeft de size van de struct gedeelte aan
*/

void* search_flag(int iSize_data)
{
  struct data_struct *pPtr = (struct data_struct*)&myarray[iSize_data];
  if (pPtr->flag ==-1)
    {
      iLengte_data = (pPtr -> size +3);// omdat we intergers gebruiken is het altijd 4 byte
      iLengte_data =5;
      return iLengte_data;
    }
    
}

/**
    @brief Kijkt waar de de gegevens geplaatst wordt in de array
*/
int check_array()
{
  iCounter =0;
  printf("%d\n", iFull );
  for (iLijst = 0; iLijst< MAX; iLijst++)
    {
      if (myarray[iLijst] == 0)
        {
        
          if (myarray[iLijst-1] == 0) // kijkt of array leeg is
            {
              iSize_data = iLijst-4;
              iCounter++;
              if (iCounter ==4)// 5 lege plekken (0-4)
                {
                 
                  iSize_data = iLijst-4;
                  

                  if (iSize_data <0)
                    {
                       iSize_data = 0;
                    }

                  
                    iCounter=0;
                    break;
                    
                }
                  else
                  {
                   iSize_data = iNumber+iLijst;
                   iFull++;
                  }
                }
                else 
                {
                  iCounter =0;
                  iFull++;
                }
        }
        else
        {
         iFull++;
        }
             
     }
 // return iSize_data;        
  //return iFull;  

}
/**
    @brief Delete de data van array
*/

int del_array(pDel)
{
  for(iArray=0;iArray<=MAX-1;iArray++)
   {
    if (&myarray[iArray] == pDel)
       {
          iCheck=0;
          while(iCheck<=4) // lengte 4 omdat het integers zijn anders gebruik we de size-1
            {
              myarray[iArray] = 0;
              iArray++;
              iCheck++;
            }
        }
       
    }
  return iArray;
  return iCheck;
}
/**
    @brief Wijzigd een nummer in de memory / array
    @param iValue dit is de ingevulde nummer
    @param pNum dit is de vervangende nummer
*/
int replace_array(int iValue, int pNum)
{
  for(iArray=0;iArray<=MAX;iArray++)
    {
     if (myarray[iArray] == iValue)
      {
        myarray[iArray] = pNum;
      }
       
    }

}