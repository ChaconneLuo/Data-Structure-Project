#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int Data;
	struct node *Next;
}Node;

Node* Init()            //创建头节点实体并调用malloc函数分配空间 
{
	Node *head = (Node*)malloc(sizeof(Node));
	head->Next = NULL;
	return head;
}

void CreateFromHead(Node *head, int ElementNumber)
{
	int TmpValue;
	for(int i = 0; i < ElementNumber; i++)
	{
		Node *tmp = (Node*)malloc(sizeof(Node));
		scanf("%d",&TmpValue);
		tmp->Data = TmpValue;
		tmp->Next = head->Next;
		head->Next = tmp;
	}
}

void CreateFromRear(Node *head,int ElementNumber)
{
	int TmpValue;
	Node *FPoint = head;
	for(int i = 0; i < ElementNumber; i++)
	{
		Node *tmp = (Node*)malloc(sizeof(Node));
		scanf("%d",&TmpValue);
		tmp->Data = TmpValue;
		tmp->Next = FPoint->Next;
		FPoint->Next = tmp;
		FPoint = tmp;
	}
}

void PrintLinkList(Node *head)
{
	Node *FPoint = head->Next;
	while(FPoint != NULL)
	{
		printf("%d ",FPoint->Data);
		FPoint = FPoint->Next;
	}
}

int main(void)
{
	int ElementNumber;        //元素个数
	Node *head = Init();
	scanf("%d",&ElementNumber);
	CreateFromHead(head,ElementNumber);      //头插法，传入头指针和元素个数 
	//CreateFromRear(head,ElementNumber);	//尾插法，传入头指针和元素个数
	PrintLinkList(head);         //打印整个链表
	return 0;
}
