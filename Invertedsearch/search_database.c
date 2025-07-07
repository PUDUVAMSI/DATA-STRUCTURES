#include"header.h"

int search_database(H_Table *table)
{
    char buffer[20];
    printf("Enter the word you want to search: ");
    scanf("%s",buffer);
    if(buffer[0]>='A' && buffer[0]<='Z')
    {
        buffer[0]=buffer[0]+32;
    }
    int ind = buffer[0] % 97;
    Main_Node *main = table[ind].link;
    while(main != NULL)
    {
        if(strcmp(main->word,buffer)==0)
        {
            printf("\t\t\t ::: DATA :::\n");
            printf("-------------------------------------------------------------\n");
            printf("%1d    %-10s     %d      ",ind,main->word,main->file_count);
            int count = main->file_count;
            Sub_Node *sub = main->sub_link;
            for(int i=0;i<count;i++)
            {
                printf("%s    %d     ",sub->file_name,sub->word_count);
                sub = sub->subl;
            }
            main = main->main_link;
            printf("\n");
            printf("--------------------------------------------------------------\n");
            return 0;
        }
        main = main->main_link;
    }
    return -3;   
}