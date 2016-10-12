#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
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

void insertSList(SList& lst,int value)
{
    printf("insert %i\n",value);
    SCell* new_cell = newSCell(value);

    SCell* actCell = lst.bidon;
    int level = lst.bestLevel;
    bool useThisCell = false;
    SCell* navigationStack[MAX_LVL+1];
    for(int i=0;i<MAX_LVL+1;++i)
    {
        navigationStack[i] = actCell;
    }

    while(level>=0 && !useThisCell)
    {
        printf("iter %i at lvl %i\n",actCell->value,level);
        if(actCell->linked[0] == NULL)
        {
            printf("link 0 = null\n");
            useThisCell = true;
        }
        else if(actCell->linked[level]==NULL)
        {
            printf("prochain link = null ");
            if(level>0)
            {
                printf("et level >0 -> level--, ");
                navigationStack[level] = actCell;
                printf("adding %i on stack lvl %i\n",actCell->value,level);
                level -= 1;
            }
            else
            {
                printf("et level=0 -> use this\n");
                useThisCell = true;
            }
        }
        else if(actCell->linked[level]->value<=value)
        {
            printf("prochaine cellule avant value\n");
            actCell = actCell->linked[level];
        }
    }
    printf("linking %i->%i\n",actCell->value,value);
    new_cell->linked[0] = actCell->linked[0];
    actCell->linked[0] = new_cell;

    if(rand()%100>50)
    {
        int promoteLevel = rand()%MAX_LVL + 1;
        printf("promote %i on level %i\n",value,promoteLevel);
        for(int i=1;i<promoteLevel;i++)
        {
            printf("  last cell linked on lvl %i is %i\n",i,navigationStack[i]);
            SCell* lastLevelCell = navigationStack[i];
            SCell* nextLevelCell = lastLevelCell->linked[i];

            new_cell->linked[i] = nextLevelCell;
            lastLevelCell->linked[i] = new_cell;
        }
        lst.bestLevel = lst.bestLevel<promoteLevel?promoteLevel:lst.bestLevel;
        printf("promote %i on %i level\n",value,promoteLevel);
    }
}

SCell* findSList(SList lst,int value)
{
    SCell* currentCell = lst.bidon;
    int level = lst.bestLevel;

    while(level>0 || currentCell->linked[level]!=NULL)
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

void deleteSList(SList& lst)
{

}
