#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define  INITSIZE 100
typedef int ElemType;
typedef struct stack
{
	int top;
	int stacksize;
	ElemType data[INITSIZE];
}sqstack;

//��ʼ��˳��ջ
void InitStack(sqstack *s)
{
	s->top = 0;
	s->stacksize = INITSIZE;
}

//�ж�ջ�Ƿ�Ϊ��
bool IsEmpty(sqstack s)
{
	return s.top == 0;
}

//�ж�ջ�Ƿ�����
bool IsFull(sqstack s)
{
	return s.top >= s.stacksize;
}

//��ջ
void Push(sqstack *s, ElemType e)
{
	if (IsFull(*s))
		return;
	else
	{
		s->data[s->top] = e;
		s->top++;
	}
}

//��ջ
void Pop(sqstack *s)
{
	if (IsEmpty(*s))
		return;
	else
		s->top--;
}

//��ȡջ��Ԫ��
void StackTop(sqstack s, ElemType *e)
{
	if (IsEmpty(s))
		return;
	else
		*e = s.data[s.top - 1];
}

//���˳��ջ 
void PrintStack(sqstack s)
{
	int i;
	for (i = s.top - 1; i >= 0; i--)
		printf("%d", s.data[i]);
	printf("\n");
}

void main()
{
	sqstack *e = (sqstack *)malloc(sizeof(sqstack));
	InitStack(e);
	Push(e, 10);
	PrintStack(*e);
	system("pause");
}