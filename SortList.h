//
// Created by ascle on 19/04/2021.
//

#ifndef ASSIGNMENT1_SORTLIST_H
#define ASSIGNMENT1_SORTLIST_H

IORB *swap(IORB *ptr1, IORB *ptr2)
{
    IORB *temp = ptr2->link;
    ptr2->link = ptr1;
    ptr1->link = temp;
    return ptr2;

}

void sortList(IORB **head, int(*prio)(int))
{
    IORB **current;
    for (int i = 0; i <= 10; i++)
    {
        current = head;
        for (int j = 0; j < 10 - i - 1; j++)
        {
            IORB *ptr1 = *current;
            IORB *ptr2 = ptr1->link;
            if (prio(ptr1->base_pri) > prio(ptr2->base_pri))
            {
                *current = swap(ptr1, ptr2);
            }
            current = &(*current)->link;
        }
    }
}

IORB *rbubble(IORB *head, int (*prio)(int))
{
    if (head->link == NULL)
        return head;

    IORB *current = head;
    while (current != NULL)
    {
        if (current->base_pri > current->link->base_pri)
            swap(current, current->link);
        else
            current = current->link;
    }

    rbubble(head->link, prio);
    return head;
}

#endif //ASSIGNMENT1_SORTLIST_H
