#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
	int Data;
	struct node *Next;
} Node;

Node *Init() //创建头节点实体并调用malloc函数分配空间
{
	Node *head = (Node *)malloc(sizeof(Node));
	if (head == NULL)
	{
		printf("Init Error!\n");
		exit(0);
	}
	head->Next = NULL;
	return head;
}

void CreateFromHead(Node *head, int ElementNumber)
{
	int TmpValue;
	for (int i = 0; i < ElementNumber; i++)
	{
		Node *tmp = (Node *)malloc(sizeof(Node));
		scanf("%d", &TmpValue);
		tmp->Data = TmpValue;
		tmp->Next = head->Next;
		head->Next = tmp;
	}
}

void CreateFromRear(Node *head, int ElementNumber)
{
	int TmpValue;
	Node *FPoint = head;
	for (int i = 0; i < ElementNumber; i++)
	{
		Node *tmp = (Node *)malloc(sizeof(Node));
		scanf("%d", &TmpValue);
		tmp->Data = TmpValue;
		tmp->Next = FPoint->Next;
		FPoint->Next = tmp;
		FPoint = tmp;
	}
}

void PrintLinkList(Node *head)
{
	Node *FPoint = head->Next;
	while (FPoint != NULL)
	{
		printf("%d ", FPoint->Data);
		FPoint = FPoint->Next;
	}
}
bool ListEmpty(Node *head)
{
	return head->Next == NULL;
}

void ClearList(Node *head)
{
	Node *tmp = head->Next;
	while (tmp)
	{
		tmp = tmp->Next;
		free(head);
		head = tmp;
	}
}

int GetElem(Node *head, int Position, int *e)
{
	Node *p = head;
	for (int i = 0; i < Position; i++)
	{
		p = p->Next;
		if (p == NULL)
		{
			exit(0);
		}
		if (i == Position - 1)
		{
			e = p->Data;
			return p->Data;
		}
	}
}

bool LocateElem(Node *head, int e)
{
	Node *tmp = head->Next;
	while (tmp)
	{
		if (tmp->Data == e)
		{
			return true;
		}
		tmp = tmp->Next;
	}
	return false;
}

void ListInsert(Node *head, int Position, int Elem)
{
	Node *p = head;
	for (int i = 0; i < Position; i++)
	{
		p = p->Next;
		if (p == NULL)
		{
			exit(0);
		}
		if (i == Position - 1)
		{
			Node *tmp = (int *)malloc(sizeof(Node));
			tmp->Data = Elem;
			tmp->Next = p->Next;
			p->Next = tmp;
		}
	}
}

void ListDelete(Node *head, int Position, int *Elem)
{
	Node *p = head;
	for (int i = 1; i < Position; i++)
	{
		p = p->Next;
		if (p == NULL)
		{
			exit(0);
		}
	}
	Node *t = p->Next;
	p->Next = p->Next->Next;
	free(t);
}

int ListLength(Node *head)
{
	Node *p = head->Next;
	int cnt = 1;
	while (p)
	{
		p = p->Next;
		cnt++;
	}
	return cnt;
}

int main(void)
{
	int ElementNumber; //元素个数
	Node *head = Init();
	scanf("%d", &ElementNumber);
	CreateFromHead(head, ElementNumber); //头插法，传入头指针和元素个数
	//CreateFromRear(head,ElementNumber);	//尾插法，传入头指针和元素个数
	PrintLinkList(head); //打印整个链表
	return 0;
}
