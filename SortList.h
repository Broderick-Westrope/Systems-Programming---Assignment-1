//
// Created by ascle on 19/04/2021.
//

#ifndef ASSIGNMENT1_SORTLIST_H
#define ASSIGNMENT1_SORTLIST_H

IORB *swap(IORB *ptr1, IORB *ptr2)
{
    IORB *tmp = ptr2->link;
    ptr2->link = ptr1;
    ptr1->link = tmp;
    return ptr2;
}

int sort(IORB *head)
{
    int size = 5;

    for (int i = 0; i < size; i++)
    {
        printf("\nLOOP 1\n");
        IORB *current = head;
        int swapped = 0;

        for (int j = 0; j < size - 1; j++)
        {
            printf("\nLOOP 2\n");
            IORB *n1 = current;
            IORB *n2 = current->link;

            if (current->link == NULL)
            {
                printf("N2/Current's link is null!!!!!!!!!\n");
            }

            printf("Current Data: %d\n", current->base_pri);
            printf("Current ID: %d\n", current->link);
            printf("N1 Data: %d\n", n1->base_pri);
            printf("N1 ID: %d\n", n1->link);
            printf("N2 Data: %d\n", n2->base_pri);
            printf("N2 ID: %d\n", n2->link);

            if (n1->base_pri > n2->base_pri)
            {
                printf("Need to switch\n");
                IORB *temp = n2->link;
                n2->link = n1;
                n1->link = temp;
                current = n2;
                if (current->link == NULL)
                {
                    printf("N2/Current's link is null!!!!!!!!!\n");
                }
                swapped = 1;
                printf("Switched\n");
            }
            printf("Past the 'if'\n");

            current = current->link;
            if (current->link == NULL)
            {
                printf("N2/Current's link is null!!!!!!!!!\n");
            }
            printf("Changed link\n");
        }
        if (swapped == 0)
        {
            printf("SORT SUCCESSFUL!!\n");
            return 1;
        }
    }

    return 0;
}

#endif //ASSIGNMENT1_SORTLIST_H
