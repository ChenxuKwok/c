// leecode 第一题 两数之和
// 耗时 8ms

#include<stdio.h>
#include<malloc.h>

//上面两个头文件只是为了vscode不报错，写题的时候可以删掉

#define HASHLISTSIZE 103
struct node;
typedef struct node* ptrToNode;
typedef ptrToNode node;
struct node
{
    int key;
    int value;
    int data;
    ptrToNode next;
};

int hash(int x);
void initializationHashList(node hashList[]);
void insert(node hashList[], int element, int index);
void readIn(node hashList[], int* nums, int numSize);
int find(node hashList[], int element, int numsIndex, int* flag);
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, toFind, result, flag;

    node hashList[HASHLISTSIZE];
    initializationHashList(hashList);
    readIn(hashList, nums, numsSize);
    for(i = 0; i < numsSize; i++)
    {
        toFind = target - nums[i];
        result = find(hashList, toFind, i, &flag);
        if(result != i && flag == 1)
        {
            int* ret;
            *returnSize = 2;
            ret = (int*)malloc(sizeof(int)*(*returnSize));
            ret[0] = i; ret[1] = result;
            return ret;
        }
    }
    *returnSize = 0;
    return NULL;
}
int hash(int x)
{
    int index;
    if(x > 0)
    {
        return x % HASHLISTSIZE;
    }else{
        x = -x;
        return (x<<5) % HASHLISTSIZE;
    }
}
void initializationHashList(node hashList[])
{
    int i;
    for(i = 0; i < HASHLISTSIZE; i++)
    {
        hashList[i] = (ptrToNode)malloc(sizeof(struct node));
        hashList[i]->key = 0;
        hashList[i]->next = NULL;
        hashList[i]->value = 0;
    }
}
void readIn(node hashList[], int* nums, int numSize)
{
    int i;
    for(i = 0; i < numSize; i++)
    {
        insert(hashList, nums[i], i);
    }
}
void insert(node hashList[], int element, int index)
{
    node nodeToInsert, tmp;
    int positionToInsert = hash(element);
    nodeToInsert = hashList[positionToInsert];
    ptrToNode ptr;
    nodeToInsert->key++;
    tmp = (ptrToNode)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->value = index;
    tmp->data = element;
    ptr = hashList[positionToInsert];
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = tmp;
}
int find(node hashList[], int element, int numsIndex, int* flag)
{
    int hashListIndex = hash(element);
    node nodeToSearch = hashList[hashListIndex];
    ptrToNode ptr = nodeToSearch;
    if(ptr->key == 0)
    {
        *flag = 0;
        return 0;
    }else{
        ptr = ptr->next;
        while (ptr != NULL)
        {
            if(ptr->data == element)
            {
                *flag = 1;
                return ptr->value;
            }
            ptr = ptr->next;
        }
    }
    *flag = 0;
    return 0;
}