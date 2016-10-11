//
//  Seats.cpp
//  HW3
//
//  Created by Tyler Veeman on 10/6/16.
//  Copyright © 2016 TylerVeeman. All rights reserved.
//
//

#include "Seats.hpp"

bool seats[11][11];

class high
{
public:
    int rowPointer = 1;
    int seatPointer = 1;
    
    bool increase()
    {
        if (seatPointer < 10)
        {
            seatPointer++;
        }
        else
        {
            if (rowPointer == 10)
            {
                return false;
            }
            else
            {
                rowPointer++;
                seatPointer = 1;
            }
        }
        return true;
    }
};

class med
{
public:
    int rowPointer = 5;
    int seatPointer = 1;
    
    bool increase()
    {
        if (seatPointer < 10)
        {
            seatPointer++;
        }
        else
        {
            if (rowPointer == 5)
            {
                rowPointer = 6;
            }
            else if (rowPointer == 6)
            {
                rowPointer = 4;
            }
            else if (rowPointer == 4)
            {
                rowPointer = 7;
            }
            else if (rowPointer == 7)
            {
                rowPointer = 3;
            }
            else if (rowPointer == 3)
            {
                rowPointer = 8;
            }
            else if (rowPointer == 8)
            {
                rowPointer = 2;
            }
            else if (rowPointer == 2)
            {
                rowPointer = 9;
            }
            else if (rowPointer == 9)
            {
                rowPointer = 1;
            }
            else if (rowPointer == 1)
            {
                rowPointer = 10;
            }
            else if (rowPointer == 10)
            {
                return false;
            }
            
            seatPointer = 1;
        }
        return true;
    }
};

class low
{
public:
    int rowPointer = 10;
    int seatPointer = 1;
    
    bool increase()
    {
        if (seatPointer < 10)
        {
            seatPointer++;
        }
        else
        {
            if (rowPointer == 1)
            {
                return false;
            }
            else
            {
                rowPointer--;
                seatPointer = 1;
            }
        }
        return true;
    }
};

high h;
med m;
low l;

bool sellNextSeat(int type)
{
    if (type == 1)
    {
        while (seats[h.rowPointer][h.seatPointer] == false)
        {
            if (!h.increase())
            {
                return false;
            }
        }
        
        seats[h.rowPointer][h.seatPointer] = false;
        h.increase();
        return true;
    }
    else if (type == 2)
    {
        while (seats[m.rowPointer][m.seatPointer] == false)
        {
            if (!m.increase())
            {
                return false;
            }
        }
        
        seats[m.rowPointer][m.seatPointer] = false;
        m.increase();
        return true;
    }
    else if (type == 3)
    {
        while (seats[l.rowPointer][l.seatPointer] == false)
        {
            if (!l.increase())
            {
                return false;
            }
        }
        
        seats[l.rowPointer][l.seatPointer] = false;
        l.increase();
        return true;
    }
    
    return false;
}
