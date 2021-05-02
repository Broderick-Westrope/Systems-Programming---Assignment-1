#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "IORB.h"
#include "SortList.h"
#include "PriComp.h"


IORB *buildList(int size);

void displayList(IORB *head, int(*prio)(int));

int main()
{
    srand(time(NULL));
    int done = 0;
    IORB *head;

    while (done == 0)
    {
        int choice = 0; //By default, our choice is 0 (Exit)

        //Ask the user what they would like to do
        printf("\nPlease enter your choice: \n");
        printf("0) Exit \n"
               "1) Build List \n"
               "2) Sort List (ascending) \n"
               "3) Display List \n"
               "Your choice: ");
        //Get the user's input for what to do
        scanf("%d", &choice);

        //Using the user's input, do the corresponding action
        switch (choice)
        {
            case 0:     //Exit the program
            {
                printf("Terminating...");
                done = 1; //Mark that we are done with the program (stops looping)
                break;
            }
            case 1:     //Build a new list of size 10
            {
                head = buildList(10); //Run the build function
                break;
            }
            case 2:     //Sort the list
            {
                if (head->link == NULL) //Debug/Check if the list is empty. If so, tell the user and don't sort
                {
                    printf("Cannot sort an empty list!\n");
                    break;
                }
                sortList(&head, priComp); //Run the sort function
//                rbubble(&head, priComp);
                printf("Sorting Complete.\n");
                break;
            }
            case 3:     //Display the list
            {
                displayList(head, priComp); //Run the display function
                break;
            }
            default:    //If the user has provided invalid input (ie. not 0-3) then exit the program
            {
                printf("Invalid input so the program will terminate now.");
                done = 1;
            }
        }
        printf("\n\n"); //Add gaps
    }

    printf("Program terminated\n");
    return 0;
}


//Recursive function to build a list of nodes of a given size
IORB *buildList(int size)
{
    IORB *this = ((IORB *) malloc(sizeof(IORB))); //Allocate the memory to be used for this node
    this->base_pri = GenerateBase();

    char fill[25];
    snprintf(fill, 25, "This is i/o request %d ", (10 - size));
    strcpy(this->filler, fill);

    if (size <= 1) //If we have reached the last node to be made
    {
        this->link = NULL; //Set its link to be NULL (nothing)
    }
    else //Else if we are still going
    {
        //Recursively call BuildList to make another node and set it as the link of this node
        this->link = (struct iorb *) buildList(size - 1);
    }

    return this; //Return this node we have just made
}

void displayList(IORB *head, int(*prio)(int))
{
    if (head->link == NULL)
        return;

    printf("%s Base Priority: %d Priority: %d\n", head->filler, head->base_pri, prio(head->base_pri));
    head = (IORB *) head->link;
    displayList(head, priComp);
}