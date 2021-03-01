#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct snode
{
	int data;
	struct snode *next;
} StackNode;

typedef struct
{
	StackNode *top;
	int cnt;
} LinkStack;

LinkStack *Init()
{
	LinkStack *L = (LinkStack *)malloc(LinkStack);
	L->top = NULL;
	L->cnt = -1;
	return L;
}

bool Push(LinkStack *L, int e)
{
	StackNode *s = (StackNode *)malloc(sizeof(StackNode));
	s->data = e;
	s->next = L->top;
	L->top = s;
	L->cnt++;
	return true;
}

bool Pop(LinkStack *L, int *e)
{
	*e = L->top->data;
	StackNode *t = L->top;
	if (L->cnt >= 0)
	{
		L->top = L->top->next;
		L->cnt--;
		free(t);
	}
	else
	{
		return false;
	}
}