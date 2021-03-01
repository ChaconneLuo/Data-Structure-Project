#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef struct
{
	int Data[MAXSIZE];
	int Last;
} SeqList;

SeqList *Init()
{
	SeqList *S = (SeqList *)malloc(sizeof(SeqList));
	if (S == NULL)
	{
		exit(0);
	}
	S->Last = -1;
	return S;
}

int SeqList_Length(SeqList *s)
{
	return (s->Last + 1);
}

void Read(SeqList *S, int ElementNumber)
{
	if (ElementNumber < 0 || ElementNumber > MAXSIZE - 1)
	{
		exit(0);
	}
	for (int i = 0; i < ElementNumber; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		S->Data[i] = tmp;
		S->Last++;
	}
}

void Insert(SeqList *S, int Position, int e)
{
	if (Position < 0 || Position > S->Last + 1 || Position > MAXSIZE - 1)
	{
		exit(0);
	}
	for (int i = S->Last; i >= Position - 1; i--)
	{
		S->Data[i + 1] = S->Data[i];
	}
	S->Data[Position - 1] = e;
	S->Last++;
}

void Delete_Position(SeqList *S, int Position)
{
	if (Position < 0 || Position > S->Last + 1 || Position > MAXSIZE - 1)
	{
		exit(0);
	}
	//*e = S->Data[Position - 1];
	for (int i = Position - 1; i <= S->Last; i++)
	{
		S->Data[i] = S->Data[i + 1];
	}
	S->Last--;
}

void Delete_Element(SeqList *S, int e)
{
	for (int j = 0; j <= S->Last; j++)
	{
		if (S->Data[j] == e)
		{
			Delete_Position(S, j + 1);
		}
	}
}

void Print(SeqList *s)
{
	if (s->Last >= 0)
	{
		for (int j = 0; j <= s->Last; j++)
		{
			printf("%d ", s->Data[j]);
		}
	}
}

int GetElem(SeqList *S, int Position)
{
	if (Position > S->Last || Position <= 0)
	{
		exit(0);
	}
	else
	{
		return S->Data[Position - 1];
	}
}

bool ListEmpty(SeqList *S)
{
	if (S->Last < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ClearList(SeqList *S)
{
	memset(S->Data, 0, sizeof(S->Data));
	S->Last = -1;
}

bool LocateElem(SeqList *S, int e)
{
	for (int i = 0; i <= S->Last, i++)
	{
		if (S->Data[i] == e)
		{
			return true;
		}
	}
	return false;
}

int main(void)
{
	int ElementNumber; //元素个数
	SeqList *S = Init();
	scanf("%d", &ElementNumber);
	Read(S, ElementNumber);
	Print(S);
	return 0;
}
