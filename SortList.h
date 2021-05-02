//
// Created by ascle on 19/04/2021.
//

#ifndef ASSIGNMENT1_SORTLIST_H
#define ASSIGNMENT1_SORTLIST_H

IORB *swap(IORB *a, IORB *b, IORB *c)
{
    if (a != NULL)
        a->link = c;

    IORB *d = c->link;
    c->link = b;
    b->link = d;
    return c;
}

IORB *findA(IORB *head, IORB *b)
{
    IORB *a = NULL;
    IORB *current = head;
    while (current != NULL)
    {
        if (current->link == b)
        {
            a = current;
        }
        current = current->link;
    }
    return a;
}

IORB *RSort(IORB *head, IORB *current, int(*prio)(int))
{
    int swapped = 0;

    if (current->link == NULL)
        return current;
    else if (current->base_pri > current->link->base_pri)
    {
        IORB *a = findA(current, head);
        current = swap(a, current, current->link);
        return current;
    }

    RSort();
}

void sortList(IORB *head, int(*prio)(int))
{
    for (int i = 0; i < 10; i++)
    {
        IORB *result = RSort(head, head, prio);
        if (result == head)
        {
            printf("SUCCESS!!!\n");
            return;
        }
    }
}

#endif //ASSIGNMENT1_SORTLIST_H
