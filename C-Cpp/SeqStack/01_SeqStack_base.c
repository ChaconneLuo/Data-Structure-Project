#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 1000

typedef struct
{
	int Data[MAXSIZE];
	int Top;
} Stack;

Stack *Init()
{
	Stack *temp = (Stack *)malloc(sizeof(Stack));
	temp->Top = -1;
	return temp;
}

void DestoryStack(Stack *s)
{
	free(Stack);
}

void ClearStack(Stack *s)
{
	s->Top = -1;
	memset(s->Data, 0, sizeof(s->Data));
}

bool StackEmpty(Stack *tmp)
{
	return tmp->Top < 0;
}

int GetTop(Stack *s)
{
	if (s->Top >= 0)
	{
		return s->Data[s->Top];
	}
	else
	{
		exit(0);
	}
}

bool Push(Stack *s, int e)
{
	if (s->Top >= MAXSIZE - 1)
	{
		return false;
	}
	else
	{
		s->Top++;
		s->Data[s->Top] = e;
		return true;
	}
}

bool Pop(Stack *s, int *e)
{
	if (s->Top < 0)
	{
		return false;
	}
	else
	{
		*e = s->Data[s->Top];
		s->Top--;
		return true;
	}
}

int StackLength(Stack *s)
{
	return (s->Top + 1);
}

int main(void)
{
	Stack *s = Init();
	return 0;
}