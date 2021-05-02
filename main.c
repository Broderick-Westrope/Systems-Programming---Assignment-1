#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "IORB.h"
#include "SortList.h"
#include "PriComp.h"


IORB *buildList(int size, int num);

void displayList(IORB *head, int(*prio)(int));

int main()
{
    srand(time(NULL));
    int done = 0;
    IORB *list;
    do
    {
        printf("Welcome to disk I/O handler, please choose an option:\n"
               "0 - Exit\n"
               "1 - Build List\n"
               "2 - Sort List (ascending)\n"
               "3 - Display List\n");
        scanf("%d", &done);
        while (done < 0 || done > 3)
            scanf("%d", &done);
        printf("Your choice: %d\n", done);

        if (done == 1)
        {
            list = buildList(10, 0);
        }
        else if (done == 2)
        {
            sortList(&list, priComp);
        }
        else if (done == 3)
            displayList(list, priComp);
    } while (done != 0);

    printf("Program terminated\n");
    return 0;
}


IORB *buildList(int size, int num)
{
    IORB *node = ((IORB *) malloc(sizeof(IORB)));
    node->base_pri = GenerateBase();
    char newFiller[25];

    snprintf(newFiller, 25, "This is i/o request %d ", num);
    strcpy(node->filler, newFiller);
    if (size == 0)
    {
        node->link = NULL;
    }
    else node->link = buildList(size - 1, num + 1);

    return node;
}

void displayList(IORB *head, int(*prio)(int))
{

    if (head->link == NULL)
        return;

    printf("%s Base_Priority: %d Priority: %d\n", head->filler, head->base_pri, priComp(head->base_pri));
    head = (IORB *) head->link;
    displayList(head, priComp);

}