#include <iostream>
#include <string>
#include "SList.h"

//-----------------------------------
SCell* newSCell(int value)
{
    SCell* ret = new SCell;
    ret->value = value;
    ret->level = 0;
    for(int i=0;i<MAX_LVL;i++)
        ret->linked[i] = NULL;
    return ret;
}
//-----------------------------------
void initSList(SList& lst)
{
    SCell* bidon = newSCell(-1);
    lst.bidon = bidon;
    lst.bestLevel = 0;
}

void insertSList(SList lst,int value)
{
    SCell newCell = newCell(value);

    while(level>0 || currentCell->linked[level]!=NULL)
    {
        if(level>0)
        {
            if(currentCell->value == value)
            {
                newCell->linked[0] = currentCell->linked[0];
                curr
            }
            else if(currentCell->linked[level]->value<=value)
            {
                currentCell = currentCell->linked[level];
            }
            else
            {
                if(level>0)
                {
                    level -= 1;
                }
                else
                {
                    return NULL;
                }
            }
        }
    }
}

SCell* findSList(SList lst,int value)
{
    SCell* currentCell = lst.bidon;
    int level = lst.bestLevel;
    bool stop = false;
    SCell* nextOnLevel = currentCell->linked[level];

    while(level>0 || currentCell->linked[level]!=NULL)
    {
        if(level>0)
        {
            if(currentCell->value == value)
            {
                return currentCell;
            }
            else if(currentCell->linked[level]->value<=value)
            {
                currentCell = currentCell->linked[level];
            }
            else
            {
                if(level>0)
                {
                    level -= 1;
                }
                else
                {
                    return NULL;
                }
            }
        }
    }
}

void deleteSList(SList& lst)
{

}
