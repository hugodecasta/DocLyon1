#ifndef SLIST_H
#define SLIST_H

#define MAX_LVL 5

typedef struct SCell
{
    int value;
    SCell* linked[MAX_LVL];
    int level;

}SCell;

typedef struct SList
{
    SCell* bidon;
    int bestLevel;

}SList;


void initSList(SList& lst);

void insertSList(SList& lst,int value);

SCell* findSList(SList lst,int value);

void deleteSList(SList& lst);

#endif // SLIST_H
