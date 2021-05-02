//
// Created by ascle on 19/04/2021.
//

#ifndef ASSIGNMENT1_IORB_H
#define ASSIGNMENT1_IORB_H

//Custom data type IORB
typedef struct iorb
{
    int base_pri; //Stores the nodes base priority
    struct iorb *link; //Stores a pointer to the next node in the list (when there is one)
    char filler[100]; //Stores the i/o request information for displaying the node
} IORB;

#endif //ASSIGNMENT1_IORB_H
