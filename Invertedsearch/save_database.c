#include"header.h"

int save_database(H_Table *table)
{
    char buffer[20];
    printf("Enter the file u want to store data: ");
    scanf("%s",buffer);
    if(strstr(buffer,".txt")==NULL)
    {
        printf("ERROR : %s file is not exits.\n",buffer);
        return -1;
    }
    FILE *fptr = fopen(buffer,"w");
    if(fptr == NULL)
    {
        printf("ERROR : File not exits...\n");
        return -1;
    }
    for(int i=0;i<27;i++)
    {
        if(table[i].link == NULL)
        {
            continue;
        }
        Main_Node *main = table[i].link;
        while(main != NULL)
        {
            fprintf(fptr,"#%d;%s;%d;",i,main->word,main->file_count);
            int count = main->file_count;
            Sub_Node *sub = main->sub_link;
            for(int i=0;i<count;i++)
            {
                fprintf(fptr,"%s;%d;",sub->file_name,sub->word_count);
                sub = sub->subl;
            }
            main = main->main_link;
            fprintf(fptr,"#\n");
        }
    }
    return 0;
}