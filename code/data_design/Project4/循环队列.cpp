#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAXCSIZE 100
typedef int ElemType;
typedef struct queue
{
	ElemType data[MAXCSIZE];
	int front;
	int rear;
}cqueue;

//初始化循环队列
void InitQueue(cqueue *que)
{
	que->front = 0;
	que->rear = 0;
}

//判断队列是否为空
bool IsEmpty(cqueue que)
{
	return que.front == que.rear;
}

//判断队列是否为满
bool IsFull(cqueue que)
{
	return (que.rear + 1) % MAXCSIZE == que.front;
}
//求队长
int GetLen(cqueue que)
{
	return(que.rear - que.front + MAXCSIZE) % MAXCSIZE;
}

//入队
void Append(cqueue *que, ElemType e)
{
	if (IsFull(*que))
		return;
	que->data[que->rear] = e;
	que->rear = (que->rear + 1) % MAXCSIZE;
}

//出队
void Serve(cqueue *que)
{
	if (IsEmpty(*que))
		return;
	que->front = (que->front + 1) % MAXCSIZE;
}

//输出队列中的数据
void PrintQueue(cqueue que)
{
	int i;
	for (i = que.front; i < que.rear;i=(i+1)%MAXCSIZE)
	{
		printf("%d", que.data[i]);
	}
}

void main()
{
	int i;
	ElemType e;
	cqueue que;
	InitQueue(&que);
	for (int i = 0; i < 10;i++)
	{
		scanf("%d", &e);
		Append(&que, e);
	}
	PrintQueue(que);
	printf("\n");
	Serve(&que);
	PrintQueue(que);
	system("pause");
}