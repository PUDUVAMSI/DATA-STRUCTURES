#include "apc.h"
#include<stdlib.h>

int insert_first(int val,Dlist **head,Dlist **tail)
{
    Dlist *temp = *head;
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        //printf(" Memory not allocated in insert_first function.\n");
        return -1;
    }
    new->pre = NULL;
    new->data = val;
    new->next = NULL; 
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return 0;
    }
    else
    {
        temp->pre = new; 
        new->next = temp;
        *head = new;
        return 0;
    }
    return -1;
}
int print_list(Dlist *head)
{
    if(head ==NULL)
    {
       // printf("INFO : List is Empty\n");
        return -1;
    }
    Dlist *temp = head;
    while(temp)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
int addition_opt(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3)
{
    Dlist *temp=tail1;
    Dlist *temp2=tail2;
    int carry = 0,val,num1,num2;
    while(temp != NULL || temp2 != NULL)
    {
        num1 = 0;
        num2 = 0;
       if(temp != NULL)
       {
           num1 = temp->data ;
       }
       if(temp2 != NULL)
       {
            num2 = temp2->data;
       }
       int res= num1 + num2 + carry;
       carry = res / 10;
       val = res % 10;
       insert_first(val,head3,tail3);
       if(temp != NULL)
       {
          temp = temp->pre;
       }
       if(temp2 != NULL)
       {
          temp2 = temp2->pre;
       }
    }
    if(carry>0)
    {
        insert_first(carry,head3,tail3);
    }
    print_list(*head3);
}

