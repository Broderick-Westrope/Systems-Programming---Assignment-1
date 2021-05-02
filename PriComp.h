//
// Created by Broderick on 19/04/2021.
//

#ifndef ASSIGNMENT1_PRICOMP_H
#define ASSIGNMENT1_PRICOMP_H

//Calculate the priority of the node using the base priority
int priComp(int base)
{
    int p = (base * 3) / 2; //The priority is the base times 3, divided by 2
    if (p > 99) //If the priority is 100 or more
        p -= 100; //Minus 100 (this adds some methodical randomness to the priority creation)
    return p; //return our priority
}

//Generate the base priority using rand
int GenerateBase()
{
    int r = rand() % 89 + 10; //get a random 2 digit number
    return r; //return our random number
}

#endif //ASSIGNMENT1_PRICOMP_H
