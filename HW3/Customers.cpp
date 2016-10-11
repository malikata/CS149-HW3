//
//  Customers.cpp
//  HW3
//
//  Created by Tyler Veeman on 10/4/16.
//  Copyright © 2016 TylerVeeman. All rights reserved.
//
//

#include "Customers.hpp"

int getRand();
int getServiceTime(int type);

std::queue <long> fillQueue(int n, std::queue <long> q, int type)
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = getRand();
    }
    std::sort(temp, temp + n);
    for (int i = 0; i < n; i++)
    {
        Customer c;
        c.arrivalTime = temp[i];
        c.serviceTime = getServiceTime(type);
        long x = (long)&c;
        q.push(x);
    }
    return q;
}

std::queue <long> getQueue(int n, int type)
{
    std::queue <long> result;
    result = fillQueue(n, result, type);
    return result;
}

int getServiceTime(int type)
{
    srand(time(NULL));
    int randNum = 0;
    if (type == 1)
    {
        randNum = rand()%(2-1 + 1) + 1;
    }
    else if (type == 2)
    {
        randNum = rand()%(4-2 + 1) + 2;
    }
    else if (type == 3)
    {
        randNum = rand()%(7-4 + 1) + 4;
    }
    return randNum;
}

int getRand()
{
    srand(time(NULL));
    return rand() % 100;
}
