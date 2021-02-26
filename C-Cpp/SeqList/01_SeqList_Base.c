#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct
{
	ElemType Data[MAXSIZE];
	int Length;
} SeqList;

SeqList *Init()
{
	SeqList *Head = (SeqList *)malloc(sizeof(SeqList));
	if (Head == NULL)
	{
		printf("Init Error!\n");
		exit(0);
	}
	Head->Length = 0;
	return Head;
}
