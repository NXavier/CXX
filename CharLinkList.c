#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct test_struct
{
    int value;
    
    struct test_struct *next;
};
int counter=0;
char myarray[160000];
struct test_struct *head = NULL;
struct test_struct *curr = NULL;

struct test_struct* create_list(int value)
{
    
    struct test_struct *ptr = (struct test_struct*)&myarray[0];
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    
    ptr->value=value;
    ptr->next = NULL;
    head = ptr;
    mymalloc();
    return ptr;
}

struct test_struct* add_to_list(int value, bool add_to_end)
{
    printf("------\n");
    printf(head);
    if(NULL == head)
    {
        return (create_list(value));

    }
    

    struct test_struct *ptr = (struct test_struct*)&myarray[0];
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    //strcpy(ptr->val, val);
    ptr->value= value;
    myarray[counter] = ptr->value;
    ptr->next = NULL;
    ptr->next = head;
    head = ptr;
   
    return ptr;
}

struct test_struct* search_in_list(int value, struct test_struct **prev)
{
    struct test_struct *ptr = head;
    struct test_struct *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value %d \n",value);

    while(ptr != NULL)
    {
        printf("%d\n",ptr->value );
        printf("%d\n",value );

        if(ptr->value==0)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)
    {
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}


int replace_number(int value)
{
    struct test_struct *prev = NULL;
    struct test_struct *replace = NULL;

    printf("\n Deleting value %d from list\n",value);
}
int delete_from_list(int value)
{
    struct test_struct *prev = NULL;
    struct test_struct *del = NULL;

    printf("\n Deleting value %d from list\n",value);

    del = search_in_list(value,&prev);
    if(del == NULL)
    {

        return -1;
    }
    else
    {
        if(prev != NULL)
            prev->next = del->next;

        if(del == curr)
        {
            curr = prev;
        }
        else if(del == head)
        {
            head = del->next;
        }
    }

    free(del);
    del = NULL;

    return 0;
}

void print_list(void)
{
    struct test_struct *ptr = head;

    printf("\n -------Printing list Start------- \n");

    while(ptr != NULL)
    {
        printf("\n %d \n",ptr->value);
        ptr = ptr->next;
        //printf("%d\n", ptr);
    }
    printf("\n -------Printing list End------- \n");

    return;
}

void mymalloc(void)
{
    int i;

    for(i=0;i<=20;i++)
    {
        printf("%d\n", i );
        printf("%d\n", myarray[i]);
    }
}

int main(void)
{
    int i = 0, ret = 0;
    struct test_struct *ptr = NULL;
    printf("Press 1 for add a word \n");
    printf("Press 2 for .... \n");
    printf("Press 3 for print list\n");

    //print_list();
    int nummer[2];
    //char text [10];
    int info;
    
    
    while (true)
    {
        printf("Press a number\n");
        scanf("%d", &info);
        //printf("Nummer: %d\n", *nummer);
        switch (info)
                {
                    case 1:
                    printf("Add a number...\n" );
                    scanf("%d", &info);
                    add_to_list(info,true);
                    break;

                    case 2:
                    printf("Delete word\n" );
                    scanf("%d", &info);
                    delete_from_list(info);
                    break;

                    case 3:
                    print_list();
                }

    }


    /*for(i = 1; i<10; i++)
    {
        scanf("%s", &text);
        //printf("helolo");
        add_to_list(text,true);
        print_list();
    }*/

    //print_list();

    /*for(i = 4; i>0; i--)
        add_to_list(i,false);

    print_list();

    /*for(i = 1; i<10; i += 4)
    {
        ptr = search_in_list(i, NULL);
        if(NULL == ptr)
        {
            printf("\n Search [val = %d] failed, no such element found\n",i);
        }
        else
        {
            printf("\n Search passed [val = %d]\n",ptr->val);
        }

        print_list();

        ret = delete_from_list(i);
        if(ret != 0)
        {
            printf("\n delete [val = %d] failed, no such element found\n",i);
        }
        else
        {
            printf("\n delete [val = %d]  passed \n",i);
        }

        print_list();
    }*/

    return 0;
}
