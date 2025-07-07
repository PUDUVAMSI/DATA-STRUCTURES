#include"header.h"

int create_database(Node *head,H_Table *table,Sub_Node **shead,Main_Node **mhead)
{
    while(head != NULL)
    {
       FILE *fptr = fopen(head->nfile_name,"r");
       if(fptr == NULL)
       {
          printf("ERROR : File not exist...\n");
          return -1;
       }
       char buffer[20];
       int ind=0;
       while(fscanf(fptr,"%s",buffer)!=EOF)
       {
           if(buffer[0]>='A' && buffer[0]<='Z')
           {
               buffer[0] = buffer[0]+32;
               ind = buffer[0] % 97;
           }
           else if(buffer[0]>='a' && buffer[0]<='z')
           {
                ind = buffer[0] % 97;
           }
           else
           {
               ind = 26;
           }
           insert_hashtable(buffer,ind,table,head->nfile_name);
       }
       fclose(fptr);
       head = head->link;
    }
    return 0;

}
int check_file(Sub_Node **stemp,char *str)
{
    Sub_Node* temp = *stemp;
    while(temp != NULL)
    {
        if(strcmp(str,temp->file_name)==0)
        {
            *stemp = temp;
            return 0;
        }
        temp=temp->subl;
    }
    return 1;
}
void insert_hashtable(char *buffer,int ind,H_Table *table,char *str)
{
    if(table[ind].link==NULL)
    {
       Main_Node *mnew = malloc(sizeof(Main_Node));
       strcpy(mnew->word,buffer);
       mnew->file_count = 1;
       mnew->sub_link = NULL;
       mnew->main_link = NULL;
       Sub_Node *snew = malloc(sizeof(Sub_Node));
       strcpy(snew->file_name,str);
       snew->word_count = 1;
       snew->subl = NULL;
       mnew->sub_link = snew;
       table[ind].link = mnew;
    }
    else 
    {
        Main_Node *temp = table[ind].link;
        Sub_Node *stemp = NULL;
        Main_Node *pre = NULL;
        int count = 0;
        while(temp != NULL)
        {
            stemp = temp->sub_link;
            if(strcmp(temp->word,buffer)==0)
            {
                count++;
                if(check_file(&stemp,str)==0)
                {
                    stemp->word_count = (stemp->word_count) + 1;
                    break;
                }
                else
                {
                    temp->file_count = (temp->file_count) + 1;
                    Sub_Node *snew1 = malloc(sizeof(Sub_Node));
                    strcpy(snew1->file_name,str);
                    snew1->word_count = 1;
                    snew1->subl = NULL;
                    Sub_Node *temp3 = stemp;
                    while(temp3->subl != NULL)
                    {
                        temp3 = temp3 -> subl;
                    }
                    temp3->subl = snew1;
                }
            }
            pre = temp;
            temp = temp->main_link;
        }
        if(count == 0)
        { 
            Main_Node *mnew = malloc(sizeof(Main_Node));
            strcpy(mnew->word,buffer);
            mnew->file_count = 1;
            mnew->sub_link = NULL;
            mnew->main_link = NULL;
            Sub_Node *snew = malloc(sizeof(Sub_Node));
            strcpy(snew->file_name,str);
            snew->word_count = 1;
            snew->subl = NULL; 
            mnew->sub_link = snew;
            pre->main_link = mnew;
        }
    }
}
