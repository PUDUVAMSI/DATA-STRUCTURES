#include "apc.h"
#include<stdlib.h>
#include<string.h>
int dl_div_insert_first(Dlist **head, Dlist **tail, int data)
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
int delete_first(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return -1;
    }
    if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail =NULL;
        return 0;
    }
    *head = (*head)->next;
    free((*head)->pre);
    (*head)->pre = NULL;
    return 0;
}
void delete_zeroes(Dlist** headR,Dlist** tailR)
{
    Dlist* temp = *headR;
    while(temp->next!=NULL)
    {
        if(temp->data!=0)
        {
            break;
        }
        delete_first(headR,tailR);
        temp = *headR;
    }
}
void div_substraction(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR)
{
    Dlist* temp = *tail1;
    Dlist* temp2 = *tail2;
    int carry=0,data;
        while(temp != NULL || temp2 != NULL)
        {
            int num1=0,num2=0;
            data=0;
            if(temp!=NULL)
            {
                num1 = temp->data;
            }
            if(temp2!=NULL)
            {
                num2 = temp2->data;
            }
            int sum = num1 + carry - num2;
            if(sum < 0)
            {
                data = num1 + carry + 10 - num2;
                carry = -1;
            }
            else{
                data = sum;
                carry = 0;
            }
            dl_div_insert_first(headR,tailR,data);
            if(temp!=NULL)
            {
                temp=temp->pre;
            }
            if(temp2!=NULL)
            {
                temp2=temp2->pre;
            }
        }
        delete_zeroes(headR,tailR);

}
int check_number(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2)
{
    int count1=0;
    int count2=0;
    Dlist* temp = *head1;
    Dlist* temp2 = *head2;
    while(temp!=NULL)
    {
        count1++;
        temp= temp->next;
    }
    while(temp2!=NULL)
    {
        count2++;
        temp2 = temp2->next;
    }
    temp = *head1;
    temp2 = *head2;
    if(count1>count2)
    {
        return 1;
    }
    else if(count2>count1)
    {
        return -1;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data > temp2->data)
            {
                return 1;
            }
            else if(temp->data < temp2->data)
            {
                return -1;
            }
            else
            {
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        return 1;
    }
    
}

int dl_div_delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return -1;
    }
    if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return 0;
    }
    Dlist* temp = *head;
    while(*head != *tail)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    free(*head);
    *head = NULL;
    *tail = NULL;
}
int divison(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR,char* argv[])
{
    long int count=0;
    int i = 1;
    char ch = argv[1][0];
    char ch1 = argv[3][0];
    while(i)
    {
        int val = check_number(head1,tail1,head2,tail2);
        if(val==-1)
        {
            i=0;
        }
        else{
            div_substraction(head1,tail1,head2,tail2,headR,tailR);
            count++;
            dl_div_delete_list(head1,tail1);
            *head1 = *headR;
            *tail1 = *tailR;
            *headR = NULL;
            *tailR = NULL;
        }
    }
    if(ch=='-' && ch1=='-')
    {

    }
    else if(ch=='-' || ch1=='-')
    {
        printf("-");
    }
    printf("%ld\n",count);
}