#include "apc.h"
#include<stdlib.h>
#include<string.h>
int dl_sub_insert_first(Dlist **head, Dlist **tail, int data)
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
void print_sub_list(Dlist *head)
{`
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head->next!=NULL)		
	    {
                if(head->data!=0)
                {
                    break;
                }   
		    head = head -> next;
	    }
        while(head)
        {
           printf("%d", head -> data);
           head = head->next; 
        }
    }
    printf("\n");
}
int substraction(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** head3,Dlist** tail3,char* argv[])
{
    Dlist* temp = *tail1;
    Dlist* temp2 = *tail2;
    int carry=0,data;
    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[3]);
    int max = 0;
    if(len2 > len1)
    {
        max = 1;
    }
    else if(len1 > len2)
    {
        max = 0;
    }
    else
    {
        int i=0;
        while(argv[1][i])
        {
            if(argv[1][i] < argv[3][i])
            {
                max = 1;
                break;
            }
            else if(argv[1][i] > argv[3][i])
            {
                break;
            }
            i++;
        }
    }
    if(max == 0)
    {
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
            dl_sub_insert_first(head3,tail3,data);
            if(temp!=NULL)
            {
                temp=temp->pre;
            }
            if(temp2!=NULL)
            {
                temp2=temp2->pre;
            }
        }
        print_sub_list(*head3);
    }
    else
    {
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
            int sum = num2 + carry - num1;
            if(sum < 0)
            {
                data = num2 + carry + 10 - num1;
                carry = -1;
            }
            else{
                data = sum;
                carry = 0;
            }
            dl_sub_insert_first(head3,tail3,data);
            if(temp!=NULL)
            {
                temp=temp->pre;
            }
            if(temp2!=NULL)
            {
                temp2=temp2->pre;
            }
        }
        printf("-");
        print_sub_list(*head3);
    }
    return 0;
}