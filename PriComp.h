//
// Created by Broderick on 19/04/2021.
//

#ifndef ASSIGNMENT1_PRICOMP_H
#define ASSIGNMENT1_PRICOMP_H

int priComp(int _base)
{
    int p = _base + 1;
    if (p > 99)
        p = 0;
    return p;
}

int GenerateBase()
{
    int r = rand() % 99;
    printf("Random priority is: %d \n", r);
    return r;
}

#endif //ASSIGNMENT1_PRICOMP_H
