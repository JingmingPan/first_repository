#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node
{
	ElemType data;//数据域
	struct node *next;//指针域
}Node,slink;

//结点构造
Node *NewNode()
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->next = NULL;
	return p;
}

Node *NewNode(ElemType e)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->next = NULL;
	p->data = e;
	return p;
}

//创建单链表
slink *Create()
{
	Node *head = NewNode();//头结点
	Node *p;
	head->next = NULL;
	for (int i = 0; i < 10;i++)
	{
		p = NewNode();
		scanf("%d", &p->data);
		p->next = head->next;
		head->next = p;
	}
	return head;
}

//求单链表的表长
int Length(slink *lst)
{
	int i = 0;
	Node *p = lst->next;
	while (p)
	{
		i++;
		p = lst->next;
	}
	return i;
}

//单链表索引
bool GetElem(slink *lst, int i, ElemType *e)
{
	Node *p = lst->next;
	int k = 1;
	while (p&&k < i)
	{
		p = p->next;
		k++;
	}
	if (p&&k<=i)
	{
		*e = p->data;
		return true;
	}
	return false;
}

//单链表的插入
bool Insert(slink *lst, int i, ElemType e)
{
	Node *p = lst->next;
	Node *q = NewNode(e);
	int k = 1;

	while (p&&k<i-1)
	{
		p = p->next;
		k++;
	}
	if (p&&k<=i)
	{
		q->next = p->next;
		p->next = q;
		return true;
	}
	return false;
}

//单链表的删除
bool Delete(slink *lst, int i)
{
	Node *p = lst->next,*q;
	int k = 1;
	while (p&&k<i-1)
	{
		p = p->next;
		k++;
	}
	if (p&&k<=i)
	{
		q = p->next;
		p->next = q->next;
		return true;
	}
	return false;
}

//单链表的打印输出
void PrintElement(ElemType e)
{
	printf("%d", e);
}

void PrintList(slink *lst)
{
	Node *p = lst->next;
	while (p)
	{
		PrintElement(p->data);
		p = p->next;
	}
	printf("\n");
}

void main()
{
	ElemType e = 60;
	slink *lst = Create();
	PrintList(lst);
	Insert(lst, 3, e);
	PrintList(lst);
	Delete(lst, 3);
	PrintList(lst);
	system("pause");
}