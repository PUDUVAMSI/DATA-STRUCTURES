#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Success 0
#define Failure -1
typedef struct Data
{
    int data;
    struct Data *next;
    struct Data *pre;
}Dlist;

int read_and_validate(char *ptr,char *qtr);
int store_operands_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *ptr,char *qtr);
int addition_opt(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3);
int substraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **head3,Dlist **tail3,char *argv[]);
int insert_first(int val,Dlist **head, Dlist **tail);
int print_list(Dlist *head);
void print_sub_list(Dlist *head);
int dl_sub_insert_first(Dlist **head, Dlist **tail, int data);
int Multip_opt(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **head3,Dlist **tail3,char *argv[]);
int sub_insert(Dlist **head, Dlist **tail, int data);
int dl_delete_list(Dlist **head,Dlist **tail);
int addition_mul(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **head3,Dlist **tail3);
int print(Dlist **head);
int divison(Dlist** head1,Dlist** tail1,Dlist** head2,Dlist** tail2,Dlist** headR,Dlist** tailR,char* argv[]);
int delete_first(Dlist **head,Dlist **tail);
#endif