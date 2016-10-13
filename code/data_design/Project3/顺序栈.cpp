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

//³õÊ¼»¯Ë³ÐòÕ»
void InitStack(sqstack *s)
{
	s->top = 0;
	s->stacksize = INITSIZE;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
bool IsEmpty(sqstack s)
{
	return s.top == 0;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÒÑÂú
bool IsFull(sqstack s)
{
	return s.top >= s.stacksize;
}

//ÈëÕ»
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

//³öÕ»
void Pop(sqstack *s)
{
	if (IsEmpty(*s))
		return;
	else
		s->top--;
}

//»ñÈ¡Õ»¶¥ÔªËØ
void StackTop(sqstack s, ElemType *e)
{
	if (IsEmpty(s))
		return;
	else
		*e = s.data[s.top - 1];
}

//Êä³öË³ÐòÕ» 
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