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
	if (Position < 0 || Position > S->Last)
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

int main(void)
{
	int ElementNumber; //元素个数
	SeqList *S = Init();
	scanf("%d", &ElementNumber);
	Read(S, ElementNumber);
	Print(S);
	return 0;
}
