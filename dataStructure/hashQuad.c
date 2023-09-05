#include"hashQuad.h"
#include<stdio.h>
#include<malloc.h>

enum kindOfEntry{legitmate, empty, Delete};
struct hashEntry
{
    ELEMENTTYPE element;
    enum kindOfEntry info;
};
typedef struct hashEntry cell;
struct hashTbl
{
    int tableSize;
    cell* theCells;
};

hashTable initializeTable(int tableSize)
{
    hashTable h;
    int i;
    
    if(tableSize < MINTABLESIZE)
    {
        printf("table size too small!!!\n");
        return NULL;
    }
    h = (hashTable)malloc(sizeof(struct hashTbl));
    if(h == NULL)
    {
        printf("out of space!!!\n");
        return NULL;
    }
    h->tableSize = tableSize;
    h->theCells = (cell*)malloc(sizeof(cell) * h->tableSize);
    if(h->theCells == NULL)
    {
        printf("out of space!!!\n");
        return NULL;
    }
    for(i = 0; i < h->tableSize; i++)
        h->theCells[i].info = empty;
    
    return h;
}

position find(ELEMENTTYPE key, hashTable h)
{
    position currentPos;
    int collisionNum;

    collisionNum = 0;
    currentPos = hash(key, h->tableSize);
    while (h->theCells[currentPos].info != empty &&
           h->theCells[currentPos].element != key)
    {
        currentPos += 2 * ++collisionNum -1;
        if(currentPos >= h->tableSize)
            currentPos -= h->tableSize;
    }
    return currentPos;
}

void insert(ELEMENTTYPE key, hashTable h)
{
    position pos;

    pos = find(key, h);
    if(h->theCells[pos].info != legitmate)
    {
        h->theCells[pos].info = legitmate;
        h->theCells[pos].element = key;
    }
}