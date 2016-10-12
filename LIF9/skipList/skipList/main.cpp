#include <iostream>
#include <string>
#include <stdio.h>
#include "SList.h"

using namespace std;

/*Skip list*/
int main()
{
    SList liste;
    SCell* cell = NULL;

    initSList(liste);
    printf("---filling part---\n");
    for(int i=0;i<20;i+=2)
    {
        insertSList(liste,i);
    }
    insertSList(liste,15);
    printf("---finding part---\n");
    cell = findSList(liste,15);
    if(cell!=NULL)
        printf("15 founded !\n");
    else
        printf("15 not in the list...\n");

    deleteSList(liste);
}
