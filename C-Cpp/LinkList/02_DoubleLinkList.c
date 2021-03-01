#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct DulNode
{
	int data;
	struct DulNode *prior;
	struct DulNode *next;
} DulNode;

DulNode* Init()
{
	DulNode *head = (DulNode*)malloc(sizeof(DulNode));
	head->next = head;
	head->prior = head;
	return head;
}

void InsertFromHead(DulNode *head, int Number)
{
	int TmpValue;
	for (int i = 0; i < Number; i++)
	{
		DulNode *tmp = (DulNode *)malloc(sizeof(DulNode));
		scanf("%d", &TmpValue);
		tmp->Data = TmpValue;
		tmp->prior = head;
		tmp->next = head->next;
		tmp->next->prior = tmp;
		head->next = tmp;
	}
}

void InsertFromRear(DulNode *head, int Number)
{
	int TmpValue;
	Node *FPoint = head;
	for (int i = 0; i < Number; i++)
	{
		DulNode *tmp = (DulNode *)malloc(sizeof(DulNode));
		scanf("%d", &TmpValue);
		tmp->Data = TmpValue;
		tmp->prior = FPoint;
		tmp->next = FPoint->next;
		tmp->next->prior = tmp;
		FPoint->Next = tmp;
		FPoint = tmp;
	}
}