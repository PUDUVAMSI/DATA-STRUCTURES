#include "header.h"
#include<string.h>
#include<stdlib.h>
int delete_node(Node** head,char* file_name)
{
    Node* temp = *head;
    Node* prev = NULL;
    while(temp!=NULL)
    {
        if(strcmp(temp->nfile_name,file_name)==0)
        {
            if(prev==NULL)
            {
                *head = temp->link;
                free(temp);
                return 0;
            }
            prev->link = temp->link;
            free(temp);
            return 0;
        }
        prev = temp;
        temp = temp->link;
    }
    return -1;
}
int update_database(H_Table* table,Node** head,int *temp)
{
    printf("Enter the file you want to upload: ");
    char file[15];
    getchar();
    scanf("%s",file);
        if(strstr(file,".txt")==NULL)
        {
            *temp = 1;
            printf("%s is not an valid argument\n",file);
            return -1;
        }
        printf("%s\n",file);
        FILE* fptr = fopen(file,"r");
        if(fptr==NULL)
        {
            *temp = 1;
            printf("ERROR: No file name %s\n",file);
            return -1;
        }
        char ch1;
        ch1 = fgetc(fptr);
        char ch2;
        fseek(fptr,-2,SEEK_END);
        ch2 = fgetc(fptr);
        rewind(fptr);
        if(ch1=='#' && ch2 == '#')
        {
            while(fscanf(fptr,"%c",&ch1)!=EOF)
            {
                char ind[3];
                for(int i=0;i<3;i++)
                {
                    ind[i] = '\0';
                }
                fscanf(fptr,"%[^;];",ind);
                int i = 0;
                int index=0;
                while(ind[i])
                {
                    index = index*10+(ind[i] - 48);
                    i++;
                }
                char word[20];
                fscanf(fptr,"%[^;];",word);
                char file_cnt[3];
                for(int i=0;i<3;i++)
                {
                    file_cnt[i] = '\0';
                }
                fscanf(fptr,"%[^;];",file_cnt);
                i = 0;
                int file_count=0;
                while(file_cnt[i])
                {
                    file_count = file_count*10+(file_cnt[i] - 48);
                    i++;
                }
                for(int i=0;i<file_count;i++)
                {
                    char file_name[20];
                    fscanf(fptr,"%[^;];",file_name);
                    char word_cnt[3];
                    for(int i=0;i<3;i++)
                    {
                        word_cnt[i] = '\0';
                    }
                    fscanf(fptr,"%[^;];",word_cnt);
                    int i = 0;
                    int word_count=0;
                    while(word_cnt[i])
                    {
                        word_count = word_count*10+(word_cnt[i] - 48);
                        i++;
                    }
                    if(table[index].link == NULL)
                    {
                        Main_Node* new = malloc(sizeof(Main_Node));
                        Sub_Node* sub_new = malloc(sizeof(Sub_Node));
                        table[index].link = new;
                        new->file_count = file_count;
                        new->main_link = NULL;
                        new->sub_link = sub_new;
                        strcpy(new->word,word);
                        sub_new->word_count=word_count;
                        sub_new->subl = NULL;
                        strcpy(sub_new->file_name,file_name);
                    }
                    else
                    {
                        Main_Node* main = table[index].link;
                        Main_Node* prev = NULL;
                        int flag = 0;
                        while(main!=NULL)
                        {
                            if(strcmp(main->word,word)==0)
                            {
                                Sub_Node* sub_node_link = malloc(sizeof(Sub_Node));
                                sub_node_link->word_count = word_count;
                                strcpy(sub_node_link->file_name,file_name);
                                Sub_Node* sub_nlink = main->sub_link;
                                Sub_Node* prev = NULL;
                                while(sub_nlink!=NULL)
                                {
                                    prev = sub_nlink;
                                    sub_nlink = sub_nlink->subl;
                                }
                                if(prev == NULL)
                                {
                                    main->sub_link = sub_node_link;
                                }
                                else{
                                prev->subl = sub_node_link;
                                }
                                flag = 1;
                                break;

                            }
                            prev = main;
                            main=main->main_link;
                        }
                        if(flag==0)
                        {
                            Main_Node* new = malloc(sizeof(Main_Node));
                            prev->main_link = new;
                            Sub_Node* sub_new = malloc(sizeof(Sub_Node));
                            new->file_count = file_count;
                            new->main_link = NULL;
                            new->sub_link = sub_new;
                            strcpy(new->word,word);
                            sub_new->word_count=word_count;
                            sub_new->subl = NULL;
                            strcpy(sub_new->file_name,file_name);
                        }

                    }
                }
                fseek(fptr,2,SEEK_CUR);
            }
        }
        else
        {
            printf("ERROR: thats not a valid file\n");
            return -1;
        }
        Node* current = *head;
        Node* next;
        while (current != NULL)
        {
            int should_delete = 0;
            for (int i = 0; i < 27; i++)
           {
               Main_Node* main = table[i].link;
               while (main != NULL)
               {
                   Sub_Node* sub = main->sub_link;
                   while (sub != NULL)
                   {
                        if (strcmp(sub->file_name, current->nfile_name) == 0)
                        {
                            should_delete = 1;
                            break;
                        }
                        sub = sub->subl;
                    }
                    if (should_delete) break;
                    main = main->main_link;
                }
                if (should_delete) break;
            }
            next = current->link;
           if (should_delete)
              delete_node(head, current->nfile_name);
           current = next;
        }

    return 0;
}