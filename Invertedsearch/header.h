#ifndef HEADER_H
#define HEADER_H
#include<stdio.h>
#include<string.h>//header files
#include<stdlib.h>

#define RESET   "\x1b[0m"//macros
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"

#define Success 0//macros
#define Failure -1
#define Datanotfound -3
#define SIZE 27
// structures
typedef struct sub_node
{
   char file_name[20];
   int word_count;
   struct sub_node *subl;
}Sub_Node;

typedef struct Main_node
{
    char word[20];
    int file_count;
    struct sub_node *sub_link;
    struct Main_node *main_link;
}Main_Node;

typedef struct Table
{
    int key;
    struct Main_node *link;
}H_Table;

typedef struct node
{
    char *nfile_name;
    struct node *link;
}Node;

int read_and_validate(int argc,char *argv[],Node **head);
void creat_table(H_Table *table,int size);
int Store_list(Node **head,char *str);
int create_database(Node *head,H_Table *table,Sub_Node **shead,Main_Node **mhead);
void insert_hashtable(char *buffer,int ind,H_Table *table,char *str);
int display_database(H_Table *table);
int save_database(H_Table *table);
int search_database(H_Table *table);
int update_database(H_Table* table,Node** head,int *temp);

#endif