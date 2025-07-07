#include "header.h"

int read_and_validate(int argc,char *argv[],Node **head)
{
    for(int i=1;i<argc;i++)
    {
        if(strstr(argv[i],".txt") == NULL)
        {
            printf("ERROR : %s file is not containing .txt",argv[i]);
            continue;
        }
        FILE *fptr = fopen(argv[i],"r");
        if(fptr == NULL)
        {
            printf("ERROR : %s file is not exist..\n",argv[i]);
            continue;
        }
        fseek(fptr,0,SEEK_END);
        if(ftell(fptr)==0)
        {
            printf("ERROR : %s file empty..\n",argv[i]);
            continue;
        }
        rewind(fptr);
        if(Store_list(head,argv[i])!=Success)
        {
             printf("ERROR : Data not inserted..\n");
        }
    }

    Node *temp = *head;
    while(temp != NULL)
    {
      printf("->%s",temp->nfile_name);
      temp = temp->link;
    }     
    return Success;
}
int Store_list(Node **head,char *str)
{
        Node *new = malloc(sizeof(Node));
        new->nfile_name = str;
        new->link = NULL;
        if(*head == NULL)
        {
            *head = new;
            return 0;
        }
        Node *temp = *head;
        Node *pre = NULL;
        while(temp != NULL)
        {
            if(strcmp(temp->nfile_name,str) == 0)
            {
                return -1;
            }
            pre = temp;
            temp = temp->link;
        }
        pre -> link = new;
        return 0;
}