#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// Quene

typedef struct Quene 
{      
    int     front;          
    int     rear;           
    BiTNode* data[MaxSize];
} SqQueue; 

SqQueue *Init()
{
	SqQueue *tmp = (SqQueue*)malloc(sizeof(SqQueue));
	tmp->front = -1;
	tmp->rear = -1;
	return tmp;
}

void InQueue(SqQueue *sq,BiTNode *B)
{
	if(sq->rear == MaxSize - 1)
		exit(2);
	sq->rear++;
	sq->data[sq->rear] = B;
}

BiTNode* OutQueue(SqQueue *sq)
{
	if(sq->front == MaxSize - 1)
		exit(1);
	sq->front++;
	return sq->data[sq->front];
}
// End
void PreOrderTraverse(BiTree T) //二叉树的先序遍历
{
    if (T == NULL)
        return;
    printf("%c ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T) //二叉树的中序遍历
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c ", T->data);
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T) //后序遍历
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c ", T->data);
}

void CreateBiTree(BiTree *T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T)
            exit(-1);
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

void LevelOrderTraversal(BiTree T)
{
	SqQueue *S = Init();
	BiTNode *temp;
	if(T == NULL)
	{
		exit(-1);
	}
	else
	{
		InQueue(S, T);
	}
	while (S->front != S->rear)
	{
		temp = OutQueue(S);
		printf("%c ", temp->data);
		if (temp->lchild != NULL) 
		{  
            InQueue(S, temp->lchild);
        }
        if (temp->rchild != NULL) 
		{ 
            InQueue(S, temp->rchild);
        }
	}
}

int main(void)
{
    BiTree T;
    CreateBiTree(&T);
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
    LevelOrderTraversal(T);
    return 0;
}