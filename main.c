//
// Created by Broderick on 19/04/2021.
//

#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#include "IORB.h"
#include "SortList.h"
#include "PriComp.h"

void DisplayList(IORB *head, int (*prio)(int));

IORB *BuildList(int size);

int main()
{
    srand(time(NULL));

    int done = 0;
    IORB *head;
    head->link = NULL;
    while (done == 0)
    {
        int choice = 0;

        printf("\nPlease enter your choice: \n");
        printf("0) Exit \n"
               "1) Build List \n"
               "2) Sort List (Ascending) \n"
               "3) Display List \n"
               "Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 0:     //Exit
            {
                printf("Exiting...");
                done = 1;
                break;
            }
            case 1:     //Build
            {
                //Build
                int size = 5;
//                printf("Enter the size of the list: ");
//                scanf("%d", &size);
                head = BuildList(size);
                printf("List Built with size %d.\n", size);
                break;
            }
            case 2:     //Sort
            {
                sort(head);
                printf("Sorting Complete.\n");
                break;
            }
            case 3:     //Display
            {
                //Display
                DisplayList(head, 0);
                printf("Displaying Complete.\n");
                break;
            }
            default:    //Invalid input defaults to Exit
            {
                printf("Invalid input so the program will exit now.");
                done = 1;
            }
        }
        printf("\n\n");
    }
    return 0;
}

IORB *BuildList(int size)
{
    IORB *this = ((IORB *) malloc(sizeof(IORB)));
    this->base_pri = GenerateBase();
    if (size <= 1)
    {
        this->link = NULL;
    }
    else
    {
        this->link = (struct iorb *) BuildList(size - 1);
    }

    return this;
}

void DisplayList(IORB *head, int(*prio)(int))
{
    IORB *temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf("Base Priority: %d \n", temp->base_pri);
        temp = temp->link;
    }
}
