//
// Created by ascle on 19/04/2021.
//

#ifndef ASSIGNMENT1_SORTLIST_H
#define ASSIGNMENT1_SORTLIST_H

void swap(IORB *b, IORB *c, IORB *cParent)
{
    IORB *temp = c->link;
    c->link = b->link;
    b->link = temp;
    if (cParent != NULL) //null if we are switching for the head because the head has no parent
        cParent->link = b;
}

IORB *getParent(IORB *head, IORB *child)
{
    IORB *current = head;
    while (current->link != NULL)
    {
        if (current->link == child)
            return current;

        current = current->link;
    }

    return NULL;
}


//Function to display all the elements of a linked list given the head node
void disp(IORB *head, int(*prio)(int))
{
    IORB *temp = head; //Create a temporary variable that points to the head node
    printf("\n"); //Add a line break
    int request = 0; //Set the request to 0 (this allows us to display what index each i/o request is
    while (temp != NULL) //While the temp isn't NULL (ie. while there are still nodes left)
    {
        //Print the information for this node including the request index, base priority, and sorting priority
        printf("Block description: this is i/o request %d Base Priority: %d Priority: %d\n", request, temp->base_pri, prio(temp->base_pri));
        temp = temp->link; //Update temp to be the next node
        request++; //Increment request to count the number of i/o requests
    }
}

IORB *sortList(IORB *head, int(*prio)(int))
{
    disp(head, prio);

    if (head->link == NULL)
        return head;

    IORB *current = head;
    IORB *best = head;
    while (current != NULL)
    {
        if (current->base_pri < best->base_pri)
            best = current;
        current = current->link;
    }

    IORB *bestParent = getParent(head, best);
    if (bestParent == NULL)
        printf("no parent for node\n");
    swap(head, best, bestParent);
    head->link = sortList(head->link, prio);

    return head;
}

#endif //ASSIGNMENT1_SORTLIST_H
