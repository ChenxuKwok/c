#ifndef _hashQuad_H
#define ELEMENTTYPE int
#define MINTABLESIZE 23
typedef unsigned int index;
typedef index position;

struct hashTbl;
typedef struct hashTbl* hashTable;

hashTable initializeTable(int tableSize);
void destroyTable(hashTable h);
position find(ELEMENTTYPE key, hashTable h);
void insert(ELEMENTTYPE key, hashTable h);
ELEMENTTYPE retrive(position p, hashTable h);
hashTable rehash(hashTable h);

#endif