#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "test.h"

/**
    @file Database.c
    @author Nilson Xavier da Luz 0838753 & Samuel Cheung 0836752
*/

/**
    @brief De methode zorgt dat een waarde in de database wordt opgeslagen
    @param iValue dit is de ingevulde nummer
*/
int saving(int iValue)
{
	
	printf("print to database\n");
	//printf("%d\n",iValue );
	//printf("%s\n",filename );
	fp=fopen(filename,"a");
	fseek(fp, 4, SEEK_END);
	fprintf(fp,"%d\n", iValue);
	//b++;
	fclose(fp);
	return 0;
}

/**
    @brief De methode zorgt dat een waarde in de database wordt opgeslagen
*/
int F2M()
{
	printf("printing\n");
	if (fopen("data.txt", "r") != NULL) {
		fp = fopen("data.txt", "r");

		if (fp != NULL)
		{
			
			int iNumberArray[5];
			int iAantal;

			for(iAantal=0; iAantal<5; iAantal++)
			{
				//iNumberArray[iAantal];
				fscanf(fp,"%d", &iNumberArray[iAantal]);
				add_to_list(iNumberArray[iAantal],true);
				//printf("%d\n",iNumberArray[iAantal]);
				
			}
		}
		fclose(fp);
	}
	else{
		printf("File does not exist\n");
		}
	return;
}