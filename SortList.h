//
// Created by ascle on 19/04/2021.
//

#ifndef ASSIGNMENT1_SORTLIST_H
#define ASSIGNMENT1_SORTLIST_H

//Swap the position of 2 nodes changing only pointers
IORB *swap(IORB *n1, IORB *n2)
{
    IORB *temp = n2->link; //Create a temporary node to store node2's link
    n2->link = n1; //Node2's link is node1
    n1->link = temp; //Node1's link is node2's old link
    return n2; //return node2
}

//Sort a list of IORB's using bubble sort for links
void sortList(IORB **head, int(*prio)(int))
{
    //For each node in the list
    for (int i = 0; i <= 10; i++)
    {
        IORB **current = head; //Current equals the head node
        int swapped = 0;
        //For all of the nodes that haven't been sorted (- i) except the last one (because when comparing a node with the next we dont need to focus on the last)
        for (int j = 0; j < 10 - i - 1; j++)
        {
            IORB *n1 = *current; //Node1 is the current node
            IORB *n2 = n1->link; //Node2 is the current node's link
            //If node1 is bigger than node2
            if (prio(n1->base_pri) > prio(n2->base_pri))
            {
                *current = swap(n1, n2); //The current node is the result of the swap (the node furthest down the line aka. n2)
                swapped = 1;
            }
            current = &(*current)->link; //Current equals the next node
        }

        if (swapped == 0)
            return;
    }
}

#endif //ASSIGNMENT1_SORTLIST_H
