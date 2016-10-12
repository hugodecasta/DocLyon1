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
    printf("|insert| %i\n",value);
    printf(".------.\n");
    SCell* new_cell = newSCell(value);

    SCell* actCell = lst.bidon;
    int level = lst.bestLevel;
    bool useThisCell = false;
    SCell* navigationStack[MAX_LVL];
    for(int i=0;i<MAX_LVL;++i)
    {
        navigationStack[i] = actCell;
    }

    while(level>=0 && !useThisCell)
    {
        printf("iter %i at lvl %i\n",actCell->value,level);

        SCell* nextCellOnLevel = actCell->linked[level];
        int nextValueOnLevel = nextCellOnLevel==NULL?-2:nextCellOnLevel->value;

        if(actCell->linked[0] == NULL)
        {
            printf("link 0 of %i is null -> linking\n",actCell->value);
            useThisCell = true;
        }
        else if(nextCellOnLevel==NULL || nextValueOnLevel>value)
        {
            printf("link of %i at lvl %i NULL ",actCell->value,level);
            if(level>0)
            {
                printf("and level > 0 -> level--");
                navigationStack[level] = actCell;
                printf("adding %i on stack lvl %i\n",actCell->value,level);
                level -= 1;
            }
            else
            {
                printf("and level==0 -> use this cell!\n");
                useThisCell = true;
            }
        }
        else
        {
            printf("next cell %i more little than %i, update currentCell\n",nextValueOnLevel,value);
            actCell = nextCellOnLevel;
        }
    }
    printf("linking %i with %i\n",actCell->value,value);
    new_cell->linked[0] = actCell->linked[0];
    actCell->linked[0] = new_cell;

    if(rand()%100>50)
    {
        int promoteLevel = rand()%(MAX_LVL-1)+1;
        printf("promote %i on level %i\n",value,promoteLevel);
        for(int i=1;i<promoteLevel+1;i++)
        {
            printf("  last cell linked on lvl %i is %i, ",i,navigationStack[i]->value);
            SCell* lastLevelCell = navigationStack[i];
            SCell* nextLevelCell = lastLevelCell->linked[i];
            if(nextLevelCell==NULL)
                printf("and next is NULL\n");
            else
                printf("and next is %i\n",nextLevelCell->value);

            new_cell->linked[i] = nextLevelCell;
            lastLevelCell->linked[i] = new_cell;
            printf("  promote linking done\n");
        }
        lst.bestLevel = lst.bestLevel<promoteLevel?promoteLevel:lst.bestLevel;
        printf("  new bestLevel %i\n",lst.bestLevel);
    }
}

SCell* findSList(SList lst,int value)
{
    SCell* currentCell = lst.bidon;
    int level = lst.bestLevel;

    while(level>=0)
    {
        printf("iter %i at lvl %i\n",currentCell->value,level);

        SCell* nextCellOnLevel = currentCell->linked[level];
        int nextValueOnLevel = nextCellOnLevel==NULL?-2:nextCellOnLevel->value;

        if(currentCell->value == value)
        {
            printf("cell founded !\n");
            return currentCell;
        }
        else if(nextCellOnLevel==NULL || nextValueOnLevel>value)
        {
            if(level>0)
            {
                printf("next cell on lvl %i is null -> level--\n",level);
                level -= 1;
            }
            else
            {
                printf("nothing else to find...\n",level);
                return NULL;
            }
        }
        else
        {
            printf("next cell %i more little than %i, update currentCell\n",nextCellOnLevel->value,value);
            currentCell = nextCellOnLevel;
        }
    }
}

void deleteSList(SList& lst)
{

}
