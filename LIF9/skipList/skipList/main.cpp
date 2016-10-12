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
    for(int i=0;i<5;i+=1)
    {
        insertSList(liste,i);
    }
    printf("---finding part---\n");
    cell = findSList(liste,8);
    if(cell!=NULL)
        printf("15 founded !\n");
    else
        printf("15 not in the list...\n");

    drawSList(liste);

    deleteSList(liste);
}
