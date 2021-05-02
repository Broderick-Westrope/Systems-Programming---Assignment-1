//
// Created by Broderick on 19/04/2021.
//

//region - References
#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#include "IORB.h"
#include "SortList.h"
#include "PriComp.h"
//endregion

//region - Prototypes
void DisplayList(IORB *head, int (*prio)(int));

IORB *BuildList(int size);
//endregion

int main()
{
    srand(time(NULL)); //Seed the random function for use later (when generating the base priority)

    int done = 0; //A variable used to check if we are done the program or not (continues when it equals 0)
    IORB *head; //A pointer to the head of the list
    head->link = NULL; //Set the pointer to NULL as there is no list yet
    while (done == 0) //While we haven't finished using the program, do the following
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
                head = BuildList(10); //Run the build function
                break;
            }
            case 2:     //Sort the list
            {
                if (head->link == NULL) //Debug/Check if the list is empty. If so, tell the user and don't sort
                {
                    printf("Cannot sort an empty list!\n");
                    break;
                }
                head = sortList(&head, priComp); //Run the sort function
                printf("Sorting Complete.\n");
                break;
            }
            case 3:     //Display the list
            {
                DisplayList(head, priComp); //Run the display function
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
    return 0;
}

//Recursive function to build a list of nodes of a given size
IORB *BuildList(int size)
{
    IORB *this = ((IORB *) malloc(sizeof(IORB))); //Allocate the memory to be used for this node
    this->base_pri = GenerateBase();
    if (size <= 1) //If we have reached the last node to be made
    {
        this->link = NULL; //Set its link to be NULL (nothing)
    }
    else //Else if we are still going
    {
        //Recursively call BuildList to make another node and set it as the link of this node
        this->link = (struct iorb *) BuildList(size - 1);
    }

    return this; //Return this node we have just made
}

//Function to display all the elements of a linked list given the head node
void DisplayList(IORB *head, int(*prio)(int))
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
