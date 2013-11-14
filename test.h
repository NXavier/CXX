#ifndef test_H_INCLUDED
#define test_H_INCLUDED

#define MAX (160000 /4)// Groote van memmory   bij testen hebben wij 50 gebruikt
/**
    @file test.h
    @author Nilson Xavier da Luz 0838753 & Samuel Cheung 0836752
*/
 /**
    @brief structure 
    */
struct data_struct
{
    int flag;
    int size;
    int iValue;
    struct data_struct *next;
    int lastflag;
};


int iNumber =0;
int iLengte_data;
int iArray;
int myarray[MAX]= {0};
int iCounter;
int iSize_data =0;
int iFull =0;
int iCheck=0;
int iLijst;
int b=0;
FILE *fp;
char filename[10];
struct data_struct *pHead = NULL;
struct data_struct *pCurr = NULL;


#endif