/*                                     :: DESCRIPTION ::

NAME : PUDU VAMSI
DATE : 20/05/2025
DESCRIPTION : The Inverted Search project is a text-processing and retrieval system designed to index and search large volumes of text data efficiently. At its core, the project implements an inverted index — a data structure that maps each word to the list of files (or documents) in which it appears. This significantly speeds up search operations, especially in environments with large text corpora.

*/

#include"header.h"

void creat_table(H_Table *table,int size)//function for the create table
{
       for(int i=0;i<size;i++)
       {
              table[i].key = i;
              table[i].link = NULL;
       }
}
int main(int argc,char *argv[])//main function
{
    if(argc>1)//check the number of arguments
    {
      Node *head = NULL;//here we are creating the nodes
      H_Table table[SIZE]; 
      Sub_Node *shead = NULL;
      Main_Node *mhead = NULL;
      creat_table(table,27);//function call
      int create = 0;
      int update = 0;
      if(read_and_validate(argc,argv,&head) == Success)//function call to check the files
      {
           int i=1;
           while(i)
           {
                 printf("\n1.Create Database\n2.Display Database\n3.Update Database\n4.Search\n5.Save Database\n6.Exit\n");//menu
                 int opt;
                 printf("Enter the Option: ");
                 scanf("%d",&opt);
                 switch(opt)//based on opt it will be jumps to that condition
                 {
                         case 1:if(create==0)
                                {
                                    printf("You have slected create database\n");
                                    create = 1;
                                    if(create_database(head,table,&shead,&mhead)==Success)//function call to create data base
                                    {
                                      printf("INFO : Successfully created data base...\n");
                                    }
                                 }
                                 else
                                 {
                                    printf("ERROR : You can't create a data base again..\n");
                                 }
                                break;
                         case 2:printf("You have slected display database\n");
                                if(display_database(table)==Success)//function call to display data base
                                {
                                   printf("\n");
                                }
                                break;  
                         case 3:if(create == 0 && update == 0)
                                {
                                   int ind = 0;
                                   printf("You have slected update database\n");
                                   if(update_database(table,&head,&ind)==Success)//function call to update data base
                                   if(ind == 0)
                                   {
                                       printf("INFO : Successfully updated data base...\n");
                                       update = 1;
                                   }
                                }
                                else
                                {
                                   printf("ERROR : You have already Updated DataBase. You can't Re-Update DataBase..\n");
                                }
                                break;
                         case 4:printf("You have slected search database\n");
                                if(search_database(table)==Datanotfound)//function call to search data base
                                {
                                   printf("ERROR : Data not found...\n");
                                }
                                else
                                {
                                   printf("\n");
                                }
                                break;  
                         case 5:printf("You have slected save database\n");
                                if(save_database(table)==Success)//function call to save data base
                                {
                                    printf("INFO : Successfully saved data base...\n");
                                }
                                break;
                         case 6:i=0;
                                printf("\t\t\t\t :::: EXIT ::::\n`");//exit
                                break;          
                         default :printf("ERROR : Please enter valid Option..\n");
                                break;
                                                      
                 }
           }
           
      }
      else
      {
         printf("ERROR : Please pass valid arguments\n");
      }
    }
    else
    {
        printf("ERROR : Please pass valid arguments a.out <file.txt>\n");
    }
}
