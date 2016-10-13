#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node
{
	ElemType data;//������
	struct node *next;//ָ����
}Node,slink;

//��㹹��
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

//����������
slink *Create()
{
	Node *head = NewNode();//ͷ���
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

//������ı�
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

//����������
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

//������Ĳ���
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

//�������ɾ��
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

//������Ĵ�ӡ���
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