//
// Created by ascle on 19/04/2021.
//

#ifndef ASSIGNMENT1_IORB_H
#define ASSIGNMENT1_IORB_H

typedef struct iorb
{
    int base_pri;
    struct iorb *link;
    char filler[100];
} IORB;

#endif //ASSIGNMENT1_IORB_H
