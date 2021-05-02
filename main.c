#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "IORB.h"
#include "SortList.h"
#include "PriComp.h"


IORB *buildList(int size);

void displayList(IORB *node, int(*prio)(int));

int main()
{
    srand(time(NULL)); //Seed the random function
    int done = 0; //Make a value to tell if we are done with the program (by default we arent done)
    IORB *head; //Create a pointer to our head node for later (NULL by default)

    while (done == 0) //While we aren't done with the program, loop the following
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
        printf("\n"); //Add gaps
    }

    return 0;
}


//Recursive function to build a list of nodes of a given size
IORB *buildList(int size)
{
    IORB *node = ((IORB *) malloc(sizeof(IORB))); //Allocate the memory to be used for node node
    node->base_pri = GenerateBase();

    char fill[25]; //Create a variable to store our filler text which is of size 25 at most
    //Copy the request index text and the index value
    snprintf(fill, 25, "This is i/o request %d ", (10 - size));
    strcpy(node->filler, fill);

    if (size <= 1) //If we have reached the last node to be made
    {
        node->link = NULL; //Set its link to be NULL (nothing)
    }
    else //Else if we are still going
    {
        //Recursively call BuildList to make another node and set it as the link of node node
        node->link = (struct iorb *) buildList(size - 1);
    }

    return node; //Return node node we have just made
}

void displayList(IORB *node, int(*prio)(int))
{
    if (node->link == NULL) //If we've readhed the end of the list, stop the recursion
        return;

    printf("%s Base Priority: %d Priority: %d\n", node->filler, node->base_pri, prio(node->base_pri)); //print the node information
    node = (IORB *) node->link; //the new node is the next node
    displayList(node, priComp); //display the next node recursively
}