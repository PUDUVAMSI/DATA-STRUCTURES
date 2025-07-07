#include "apc.h"
int sub_insert(Dlist **head, Dlist **tail, int data)
{
    if(*head == NULL)
    {
        Dlist* temp = (Dlist*)malloc(sizeof(Dlist));
        temp->data = data;
        temp->pre = NULL;
        temp->next = NULL;
        *head = temp;
        *tail = temp;
        return 0;
    }
    else
    {
        Dlist* temp = (Dlist*)malloc(sizeof(Dlist));
        temp->data = data;
        temp->pre = NULL;
        temp->next = NULL;
        temp->next = *head;
        (*head)->pre = temp;
        *head = temp;
        return 0;
    }
    return -1;
    
}
int dl_delete_list(Dlist **head,Dlist **tail)
{
   Dlist *temp = NULL;
   if(*head == NULL)
   {
      return -1;
   }
   while(*head != 0)
   {
      temp = *head;
      *head = (*head)->next;
      free(temp);
   }
}
int Multip_opt(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **head3,Dlist **tail3,char *argv[])
{
    Dlist *temp=*tail1;
    Dlist *temp2=*tail2;
    Dlist *back_up_head = NULL;
    Dlist *back_up_tail = NULL;
    Dlist *head = NULL;
    Dlist *tail = NULL;
    int count =0,carry = 0,val,num1,num2;
    while(temp2 !=NULL)
   {
      temp = *tail1;
      carry=0;
      for(int i=0;i<count;i++)
      {
         sub_insert(&head,&tail,0);
      }
      while(temp != NULL)
      {
         num1 = temp2->data;
         num2 = temp->data;
         val = (num1 * num2) + carry;
         carry = val / 10;
         val = val % 10;
         if(count == 0)
         {
            sub_insert(head3,tail3,val);
         }
         else
         {
            sub_insert(&head,&tail,val);
         }
         temp = temp->pre;
      }
      if(carry>0)
      {
         if(count ==0 )
         {
            sub_insert(head3,tail3,carry);
         }
         else
         {
            sub_insert(&head,&tail,carry);
         }
      }
      if(count != 0)
      {
         addition_mul(*head3,*tail3,head,tail,&back_up_head,&back_up_tail);
         dl_delete_list(head3,tail3);
         dl_delete_list(&head,&tail);
         *head3 = back_up_head;
         *tail3 = back_up_tail;
         back_up_head = NULL;
         back_up_tail = NULL;
      }
      count ++;
      temp2 = temp2 -> pre;
   }
   print(head3);

    
}
int print(Dlist **head)
{
    if(*head ==NULL)
    {
        printf("INFO : List is Empty\n");
        return -1;
    }
    Dlist *temp = *head;
    while(temp)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
int addition_mul(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3)
{
    Dlist *temp=tail1;
    Dlist *temp2=tail2;
    int carry = 0,val,num1,num2;
    while(temp != NULL || temp2 != NULL)
    {
      num1=0;num2=0;
       if(temp != NULL)
       {
           num1 = temp->data;
       }
       if(temp2 != NULL)
       {
            num2 = temp2->data;
       }
       int res= num1 + num2 + carry;
       carry = res / 10;
       val = res % 10;
       sub_insert(head3,tail3,val);
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
        sub_insert(head3,tail3,carry);
    }
}


