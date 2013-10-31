#include <stdio.h>
#include <string.h>

#pragma (push,1)
typedef struct _data
{
    char flag;
    int data;
} data;

int main()
{
  int b;
  int memory = 20;
  long long array[1600]={0}; 
  int a;
 for (b = 0; b< 20; b += 1)
                    {
                  //data * c = array[b];
                     printf("%d\n", array[b]);
                     // printf("%d\n", (int) *(c->flag));
                    }
  

data *newData = (data *)&array[0];
  char command[20];
  int x =0;


 while (1){
  printf ("doe iets\n");
  scanf("%s", &command);
  


  if (command[0] == 'a' )
  {
    if (command[1] == 'd' )
    {
        if (command[2] == 'd' )
        {
          printf("%s\n","What do you want to add" );
           
          newData -> flag =1;
          array[x] = newData -> flag;
          
          x++;
         scanf("%d", &a);
        
          array[x] = a;
           printf("You added to the list: %d\n", a);
           printf("You added to the list: %d\n", array[x]);
          x++;
          array[x] = (int)log10(a)+1;;
           printf("You added to the list: %d\n", a);
           printf("You added to the list: %d\n", array[x]);
          x++;

         
          
        }
    }
  }
    if (command[0] == 'e' )
  {
    if (command[1] == 'x' )
    {
        if (command[2] == 'i' )
        {
          if (command[3] == 't' )
          {
                 printf("%s\n","Exit system" );
                   
                system("pause");
                return 0;
          }

         }
    }
  }
    if (command[0] == 'p' )
  {
    if (command[1] == 'r' )
    {
        if (command[2] == 'i' )
        {
          if (command[3] == 'n' )
          {
              if (command[4] == 't' )
              {
                  for (b = 0; b< 20; b += 1)
                    {
                  //data * c = array[b];
                     printf("%d\n", array[b]);
                     // printf("%d\n", (int) *(c->flag));
                    }
                
                
              }  
          }

         }
    }
  }



 
}
}