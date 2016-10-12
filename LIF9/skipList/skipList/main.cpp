#include <iostream>
#include <string>

using namespace std;

/*Skip list*/
int main()
{
    SList liste;
    SCell* cell = NULL;

    initSList(liste);
    for(int i=0;i<10000;i++)
    {
        insertSList(liste,i);
    }

    cell = findSList(liste,15);
    if(cell!=NULL)
        printf("15 founded !\n"),
    else
        printf("15 not in the list...\n");

    deleteSList(liste);
}
