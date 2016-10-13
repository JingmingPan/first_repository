#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;
#define INITSIZE 100
typedef struct  node
{
	ElemType data;
	struct node *Lchild, *Rchild;
}Node,BitTree;

typedef struct stack
{
	int top;
	int stacksize;
	BitTree * data[INITSIZE];
}Stack;

typedef struct queue
{
	BitTree *data[INITSIZE];
	int front;
	int rear;
}cqueue;

void Push(Stack *s, BitTree *root)
{
	if (s->top == s->stacksize)
		return;
	else
	{
		s->data[s->top] = root;
		s->top++;
	}
}

void InitStack(Stack *s)
{
	s->top = 0;
	s->stacksize = INITSIZE;
}

void  Pop(Stack *s)
{
	if (s->top == s->stacksize)
		return;
	else
		s->top--;
}

void StackTop(Stack s,Node **n)
{
	if (s.top == s.stacksize)
		return;
	else
		*n = s.data[s.top-1];
}
//初始化队列
void InitQueue(cqueue *que)
{
	que->front = 0;
	que->rear = 0;
}
//入队
void Append(cqueue *que, BitTree *root)
{
	if ((que->rear + 1) % INITSIZE == que->front)
		return;

	que->data[que->rear] = root;
	que->rear = (que->rear + 1) % INITSIZE;
}

//出队
void Serve(cqueue &que, Node **node)
{
	if (que.front == que.rear)
		return;

	*node = que.data[que.front];
	que.front = (que.front + 1) % INITSIZE;
}


Node *NewNode()
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->Lchild = NULL;
	p->Rchild = NULL;

	return p;
}

Node *NewNode(ElemType e)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->Rchild = NULL;
	p->Lchild = NULL;
	p->data = e;

	return p;
}

void MakeBT(BitTree **bt, ElemType e, BitTree *lbt, BitTree *rbt)
{
	Node *p = NewNode(e);
	p->Lchild = lbt;
	p->Rchild = rbt;
	*bt = p;
}

//二叉树非递归中序遍历
void inorder(BitTree *root, Stack s)
{
	Node *p = NewNode();
	Push(&s, root);

	while (!(s.top==0))
	{
		StackTop(s, &p);
		while (p)
		{
			Push(&s, p->Lchild);
			p = p->Lchild;
		}
		Pop(&s); //空指针退栈
		
		if (!(s.top==0))
		{
			StackTop(s, &p);
			Pop(&s);
			printf("%d ", p->data);
			Push(&s, p->Rchild);
		}
	}
}


//层序遍历
void FloorOrder(BitTree *root, cqueue q)
{
	Node *p = NewNode();
	Append(&q, root);

	while (!(q.front==q.rear))
	{
		Serve(q, &p);
		printf("%d ", p->data);
		if (p->Lchild!=NULL)
		{
			Append(&q, p->Lchild); 
		}
		if (p->Rchild!=NULL)
		{
			Append(&q, p->Rchild);
		}
	}

}

void main()
{
	BitTree *bt = NULL, *bt1 = NULL, *bt2 = NULL, *bt3 = NULL;

	MakeBT(&bt2, 10, bt1, bt1);
	MakeBT(&bt3, 20, bt1, bt1);
	MakeBT(&bt, 30, bt2, bt3);
	MakeBT(&bt, 40, bt, bt2);
	MakeBT(&bt, 50, bt2, bt);

	Stack *e = (Stack *)malloc(sizeof(Stack));
	InitStack(e);
	inorder(bt, *e);
	printf("\n");

	cqueue que;
	InitQueue(&que);
	FloorOrder(bt, que);
	printf("\n");

	system("pause");
}