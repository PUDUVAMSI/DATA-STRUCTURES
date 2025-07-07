#include "header.h"

int display_database(H_Table *table)
{
     printf("\t\t    ::: DATA :::\n");
     printf("------------------------------------------------------\n");
     printf(BLUE"Index  Word       File_count     File       Word_count"RESET);
     printf("\n------------------------------------------------------\n\n");
    for(int i=0;i<27;i++)
    {
        if(table[i].link == NULL)
        {
            continue;
        }
        Main_Node *main = table[i].link;
        while(main != NULL)
        {
            printf(GREEN"%2d     %-10s      %d      "RESET,i,main->word,main->file_count);
            int count = main->file_count;
            Sub_Node *sub = main->sub_link;
            int flag = 0,f=0;
            for(int i=0;i<count;i++)
            {
                if(flag==0)
                {
                    printf(GREEN" %-12s      "RESET,sub->file_name);
                }
                if(flag == 0)
                {
                   printf(GREEN" %2d "RESET,sub->word_count);
                   flag++;
                }
                if(f != 0)
                {
                  printf("\n");
                  printf(GREEN"                               %-12s       %2d"RESET,sub->file_name,sub->word_count);
                }
                f++;
                sub = sub->subl;
            }
            main = main->main_link;
            printf("\n");
        }
    }
    printf("\n");
    printf("------------------------------------------------------\n");
}