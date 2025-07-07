/*   
                                 ::DESCRIPTION::
NAME : PUDU VAMSI
DATE : 20/05/2025
DESCRIPTION : The Arbitrary Precision Calculator project is designed to perform arithmetic operations on very large numbers with no fixed size limitation, making it ideal for applications where standard data types fall short. This project demonstrates the use of custom data structures to represent and manipulate numbers of arbitrary length, showcasing a practical implementation of core concepts in data structures and algorithms.

*/


#include<stdio.h>//header files
#include "apc.h"

int main(int argc,char *argv[])//main function. we are collecting the arguments from the command line 
{
    Dlist *head1=NULL;
    Dlist *head2=NULL;
    Dlist *head3=NULL;
    Dlist *tail1=NULL;
    Dlist *tail2=NULL;
    Dlist *tail3=NULL;
    if(argc == 4)//we are checking the arguments
    {
         if(read_and_validate(argv[1],argv[3]) == Success)//function call we are validating the arguments
         {
               //printf("INFO : Read and validate done successfully.\n");
               if(store_operands_list(&head1,&tail1,&head2,&tail2,argv[1],argv[3]) == Success)//function call we are storeing the arguments into list
               {
                 //printf("INFO : Stored Opernds to list Successfully.\n");
                 char ch = argv[2][0];
                 switch(ch)
                 {
                       case '+'://printf("INFO : We are performing the addition operation.\n");
                                if(addition_opt(head1,tail1,head2,tail2,&head3,&tail3)==Success)//function call for addition operation
                                {
                                     printf("\n");
                                }
                                break;
                       case '-':if(substraction(&head1,&tail1,&head2,&tail2,&head3,&tail3,argv)==Success) //function call for substraction operation
                                {
                                    printf("\n");
                                } 
                                break;
                       case 'x':if(Multip_opt(&head1,&tail1,&head2,&tail2,&head3,&tail3,argv) == Success)//function call for multiplication operation
                                {
                                    printf("\n");   
                                }
                                break;
                       case '/':if(divison(&head1,&tail1,&head2,&tail2,&head3,&tail3,argv)== Success)//function call for divison operation
                                {
                                    printf("\n");    
                                }
                                break;
                       default :printf("ERROR : Invalid Argument...\n");
                                break;       
                                
                 }
               }
               else
               {
                  // printf("ERROR : Not Stored the Opernds to list.\n");
                  return -1;
               }
         }
         else
         {
            //printf("ERROR : Read and validate function.\n");
            return -1;
         }
    }
    else
    {
        //printf("ERROR : Invalid arguments.\n");
        return -1;
    }
    
}