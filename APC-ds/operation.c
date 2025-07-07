#include "apc.h"
#include<stdlib.h>

int read_and_validate(char *ptr,char *qtr)
{
           int i=0;
           while(ptr[i] != '\0')
           {
               if(ptr[i] >= '0' && ptr[i] <= '9')
               {
                   i++;
               }
               else
               {
                   return -1;
               }
           }
           i=0;
           while(qtr[i] != '\0')
           {
               if(qtr[i] >= '0' && qtr[i] <= '9')
               {
                   i++;
               }
               else
               {
                   return -1;
               }
           }
           return 0;
     

}

int store_operands_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *ptr,char *qtr)
{
    int i=0;
    while(ptr[i] !='\0')
    {
        int da = ptr[i] - '0';
        Dlist *new= malloc(sizeof(Dlist));
        if(new==NULL)
        {
           // printf("ERROR : malloc failed at 1\n");
            return -1;
        }
        new->pre=NULL;
        new->data= da;
        new->next=NULL;
        if(*head1 == NULL)
        {
            *head1= new;
            *tail1 =new;
        }
        else
        {
         Dlist *tp1=*tail1;
         tp1->next = new;
         new->pre=tp1;
         *tail1=new;
        }  
        i++;    
    }
   // printf("INFO : Successfully copied the operand1 to list1.\n");
    i=0;
    while(qtr[i] !='\0')
    {
        int da = qtr[i] - '0';
        Dlist *new= malloc(sizeof(Dlist));
        if(new==NULL)
        {
            //printf("ERROR : malloc failed at 2\n");
            return -1;
        }
        new->pre=NULL;
        new->data= da;
        new->next=NULL;
        if(*head2 == NULL)
        {
            *head2= new;
            *tail2 =new;
        }
        else
        {
         Dlist *tp=*tail2;
         tp->next = new;
         new->pre=tp;
         *tail2=new;
        }
        i++;
      
    }
    //printf("INFO : Successfully copied the operand2 to list2.\n");
    return 0;
}