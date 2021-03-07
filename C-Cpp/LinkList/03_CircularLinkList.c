#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

Node* Init()
{
	Node *head = (Node*)malloc(sizeof(Node));
	head->next = head;
	return head;
}

void CreateFromHead(Node *head,int Number)
{
	int temp;
	for(int i = 0; i < Number; i++)
	{
		Node *tmp = (Node*)malloc(sizeof(Node));
		scanf("%d",&temp);
		tmp->data = temp;
		tmp->next = head->next;
		head->next = tmp;
	}
}

void CreateFromRear(Node *head,int Number)
{
	int temp;
	Node *p = head;
	for(int i = 0; i < Number; i++)
	{
		Node *tmp = (Node*)malloc(sizeof(Node));
		scanf("%d",&temp);
		tmp->data = temp;
		tmp->next = p->next;
		p->next = tmp;
		p = tmp;
	}
}